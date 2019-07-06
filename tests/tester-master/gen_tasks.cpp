// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gen_tasks.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 20:58:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 21:11:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tester.hpp"
#include "SuperficialHSet.hpp"
#include "ExhaustiveHeap.hpp"

// # include <unordered_map>
// # include <map>
// # include <unordered_set>
// # include <set>
// # include <vector>

// # include <cstdlib>
// # include <fstream>
// # include <assert.h>


template <class T>
static constexpr double dbl(T v) {
	return static_cast<double>(v);
}
template <class T>
static constexpr ssize_t ll(T v) {
	return static_cast<ssize_t>(v);
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

static std::string filename_of_pcvec(std::vector<Piece const*> const &pcvec)
{
	std::string ret("./map/");

	for (auto const &p : pcvec)
	{
		ret.append(itostrb62(p->uid()));
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


static auto build_files_and_tests(
	IComboGen *cg, char const *const av[], int const pptest, int const ntests)
	-> std::vector<UnitTest>
{
	std::vector<UnitTest> tasks;
	std::vector<Piece const *> pcvec(pptest);
	std::string fname;
	std::ofstream f;

	for (int i = 0; i < ntests; i++)
	{
		cg->giveNextCombo(pcvec);
		fname = filename_of_pcvec(pcvec);
		f.open(fname, std::ios_base::out | std::ios_base::trunc);
		assert(f.good()); /* file creation failed */
		for (auto const &p : pcvec)
		{
			if (&p != &*pcvec.begin()) /* funny line, but it works!!! */
				f << '\n';
			p->dump(f);
		}
		assert(f.good()); /* file write failed */
		f.close();
		assert(f.good()); /* file close failed */
		tasks.push_back(UnitTest(av[3], fname));
		tasks.push_back(UnitTest(av[4], fname));
	}
	return std::move(tasks);
}

#define MVGET(TUP, I) std::move(std::get<I>(TUP))
std::vector<UnitTest> build_tasks(char const *const av[])
{
	int const npcs = std::atoi(av[1]);
	int const ntests = std::atoi(av[2]);
	double maxtestsf;
	double ntestsf;
	PiecesStash const ps;
	// IComboGen *cg;
	std::unique_ptr<IComboGen> cg;
	int err;

	if (npcs < 0)
	{
		std::cerr << "Bad grids per tests " << npcs << std::endl;
		::exit(1);
	}
	if (ntests <= 0)
	{
		std::cerr << "Bad num tests " << ntests << std::endl;
		::exit(1);
	}

	std::cout << "\rRemoving ./map ./log                      ";
	std::cout.flush();
	err = ::system("rm -rf map log; mkdir -p log map; false");
	assert(err >= 0);

	std::cout << "\rGenerating combinations                   ";
	std::cout.flush();
	maxtestsf = std::pow(dbl(PiecesStash::numValidUid), dbl(npcs));
	ntestsf = std::min(dbl(ntests), maxtestsf);
	if (ntestsf / maxtestsf > .5) /*more than half of overall tests to gen*/
		cg.reset(new ExhaustiveHeap(ps, npcs));
	else
		cg.reset(new SuperficialHSet(ps, npcs));

	std::cout << "\rGenerating map files                      ";
	std::cout.flush();
	return build_files_and_tests(cg.get(), av, npcs, ll(ntestsf));
}
