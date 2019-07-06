
#include "tester.hpp"

struct Piece
{
	char    val[4][5];
	unsigned int adjDiff(void) { /* used to disambiguate valid and invalid pieces */
		unsigned int    acc = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 3; x++)
				if (val[y][x] == '#' && val[y][x + 1] == '#')
					acc++;
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#' && val[y + 1][x] == '#')
					acc++;
		return acc;
	}
	unsigned int type(void) { /* used to disambiguate the 19 different shapes */
		int             pos = 0;
		unsigned int    h = 0;
		int             fx = -1;
		int             fy = -1;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#')
				{
					if (fx < 0)
						fx = x, fy = y;
					else
					{
						h += (x - fx + 2) << 4 * pos++;
						h += (y - fy + 2) << 4 * pos++;
					}
				}
		return h;
	}
	unsigned int uid(void) const { /* used to disambiguate the 2^(4*4) different grids */
		unsigned int h = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				h = (h << 1) + (this->val[y][x] == '#' ? 1 : 0);
		return h;
	}
	void dump(void) {
		std::for_each(std::begin(val), std::end(val)
					  , [](char l[5]){std::cout << l << '\n';});
	}
	void dump(std::ofstream &os) const {
		for (auto const &l : val)
			os << l << '\n';
	}
};

typedef std::unordered_multimap<unsigned int, Piece> pmap_t;
typedef std::unordered_set<unsigned int> pset_t;

static void gen(Piece &p, pmap_t &pmap, pset_t &pset, int count, int istart)
{
	int     y;
	int     x;

	if (count < 4)
	{
		for (int i = istart; i < 16; i++)
		{
			y = i / 4;
			x = i % 4;
			p.val[y][x] = '#';
			gen(p, pmap, pset, count + 1, i + 1);
			p.val[y][x] = '.';
		}
	}
	else if (p.adjDiff() >= 3)
	{
		pmap.insert({p.type(), p});
		pset.insert(p.type());
	}
}

static unsigned int randType(pset_t &pset)
{
	int const   n = std::rand() % pset.size();
	int         i = 0;

	for (auto t : pset)
		if (i++ == n)
			return t;
	assert(false); /* should not be reached */
}

static Piece &randPiece(pmap_t &pmap, pset_t &pset)
{
	unsigned int const  t = randType(pset);
	unsigned int const  n = std::rand() % pmap.count(t);
	auto const          range = pmap.equal_range(t);
	unsigned int        i = 0;

	for (auto it = range.first; it != range.second; ++it)
		if (i++ == n)
			return it->second;
	assert(false); /* should not be reached */
}

char const b62[] = "0123456789"
				  "abcdefghijklmnopqrstuvwxyz"
				  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static std::string itostrb62(unsigned int i)
{
	std::string str;

	if (i == 0)
		return "0";
	while (i != 0)
	{
		str.insert(str.begin(), b62[i % 62]);
		i /= 62;
	}
	return str;
}


static std::string filename_of_pvec(std::vector<Piece> const &pvec)
{
	std::string ret("./map/");

	for (auto const &p : pvec)
	{
		ret.append(itostrb62(p.uid()));
		ret.append("_");
	}
	if (ret.size() > 200)
	{
		ret.erase(200);
		ret.append("...");
	}
	ret.append(".fillit");
	return ret;
}

std::vector<UnitTest> build_tasks(char const *const av[])
{
	std::vector<UnitTest> tasks;
	std::unordered_multimap<unsigned int, Piece> pmap;
	std::unordered_set<unsigned int> pset;
	std::vector<Piece> pvec;
	Piece p = {"....", "....", "....", "...."};
	int const pptest = std::atoi(av[1]);
	int const ntests = std::atoi(av[2]);
	std::string fname;
	std::ofstream f;
	int err;

	if (pptest < 0)
	{
		std::cerr << "Bad grids per tests " << pptest << std::endl;
		::exit(1);
	}
	if (ntests <= 0)
	{
		std::cerr << "Bad num tests " << ntests << std::endl;
		::exit(1);
	}
	gen(p, pmap, pset, 0, 0);
	err = ::system("rm -rf map log; mkdir -p log map; false");
	assert(err >= 0);
	for (int i = 0; i < ntests; i++)
	{
		pvec.clear();
		for (int j = 0; j < pptest; j++)
			pvec.push_back(randPiece(pmap, pset));
		fname = filename_of_pvec(pvec);
		f.open(fname, std::ios_base::out | std::ios_base::trunc);
		assert(f.good()); /* file creation failed */
		for (auto const &p : pvec)
		{
			if (&p != &*pvec.begin()) /* funny line, but it works!!! */
				f << '\n';
			p.dump(f);
		}
		assert(f.good()); /* file write failed */
		f.close();
		assert(f.good()); /* file close failed */
		tasks.push_back(std::move(UnitTest(av[3], fname)));
		tasks.push_back(std::move(UnitTest(av[4], fname)));
	}
	return tasks;
}
