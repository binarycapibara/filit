/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:03:57 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/08 19:18:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h> //TO REMOVE LATER

#define qprintf(...) dprintf(2, __VA_ARGS__)


typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct
{
	int			sid;	/* Shape ID */
	uintmax_t	mask;
	__uint128_t	mask128;
	int			w;
	int			h;
	t_vec2i		dt[4];
	t_vec2i		finalpos;
	char		character;
}				t_piece;

#define MAP_W 13

typedef char		t_map[MAP_W][MAP_W];

typedef struct
{
	t_piece		pcs[27];
	int			lastpid;
}				t_ppool;








/*
** Slave functions for fallback algorithm
*/
static void		load_marks(t_map m, char *marks[const 4]
						   , t_vec2i const c, t_vec2i const dt[const 4])
{
	marks[0] = &m[c.y + dt[0].y][c.x + dt[0].x];
	marks[1] = &m[c.y + dt[1].y][c.x + dt[1].x];
	marks[2] = &m[c.y + dt[2].y][c.x + dt[2].x];
	marks[3] = &m[c.y + dt[3].y][c.x + dt[3].x];
	return ;
}

static void		apply_marks(char *const marks[const 4], char const c)
{
	*marks[0] = c;
	*marks[1] = c;
	*marks[2] = c;
	*marks[3] = c;
	return ;
}

static void		increment_marks(char *marks[const 4])
{
	marks[0]++;
	marks[1]++;
	marks[2]++;
	marks[3]++;
	return ;
}

static bool		check_marks(char *const marks[const 4])
{
	return (*marks[0] == '.' && *marks[1] == '.'
			&& *marks[2] == '.' && *marks[3] == '.');
}

static void		unapply_marks(char *const marks[const 4])
{
	*marks[0] = '.';
	*marks[1] = '.';
	*marks[2] = '.';
	*marks[3] = '.';
	return ;
}







/*
** Fallback algorithm (char*) when w > sizeof(uintmax_t)
** Writes result to t_map
*/

static bool		loop_coords(t_map m, t_ppool const *const restrict pool
							, int const w
							, int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	char					*marks[4];

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		load_marks(m, marks, c, p->dt);
		while (c.x <= w - p->w)
		{
			if (check_marks(marks))
			{
				apply_marks(marks, p->character);
				if (pid == pool->lastpid || loop_coords(m, pool, w, pid + 1))
					return true;
				unapply_marks(marks);
			}
			increment_marks(marks);
			c.x++;
		}
		c.y++;
	}
	return false;
}

/*
** Main algorithm (bitwise) when w <= sizeof(uintmax_t)
** Writes result to pool[]->finalpos
** *
** Without -O2 'static' does nothing
** With -O2 'static' speeds things up by 14%
*/

static bool		loop_coords2(uintmax_t const m, t_ppool *const pool
							 , int const w
							 , int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	uintmax_t				pmask;

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask << (8 * c.y);
		while (c.x <= w - p->w)
		{
			if ((pmask & m) == 0)
			{
				if (pid == pool->lastpid || loop_coords2(m | pmask, pool, w, pid + 1))
				{
					pool->pcs[pid].finalpos = c;
					return true;
				}
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return false;
}

static bool		loop_coords3(__uint128_t const m, t_ppool *const pool
							 , int const w
							 , int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	__uint128_t				pmask;

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask128 << (11 * c.y);
		while (c.x <= w - p->w)
		{
			if ((pmask & m) == 0)
			{
				if (pid == pool->lastpid || loop_coords3(m | pmask, pool, w, pid + 1))
				{
					pool->pcs[pid].finalpos = c;
					return true;
				}
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return false;
}



/*
** __uint128_t *const m		same virtual map as in space_left
** __uint128_t cmask		current coord mask while recursing
*/
static unsigned int follow(__uint128_t *const m, int const w
						   , __uint128_t *cmask, t_vec2i c)
{
	unsigned int space;

	*m |= *cmask;
	space = 1;
	if (c.y > 0) //top (>> 11) (-1y)
	{
		*cmask >>= 11;
		if ((*m & *cmask) == 0)
			space += follow(m, w, cmask, (t_vec2i){c.x, c.y - 1});
		*cmask <<= 11;
	}
	if (c.y < w - 1) //bottom (<< 11) (+1y)
	{
		*cmask <<= 11;
		if ((*m & *cmask) == 0)
			space += follow(m, w, cmask, (t_vec2i){c.x, c.y + 1});
		*cmask >>= 11;
	}
	if (c.x > 0) //left (>> 1) (-1x)
	{
		*cmask >>= 1;
		if ((*m & *cmask) == 0)
			space += follow(m, w, cmask, (t_vec2i){c.x - 1, c.y});
		*cmask <<= 1;
	}
	if (c.x < w - 1) //right (<< 1) (+1x)
	{
		*cmask <<= 1;
		if ((*m & *cmask) == 0)
			space += follow(m, w, cmask, (t_vec2i){c.x + 1, c.y});
		*cmask >>= 1;
	}
	return space;
}

/*
** __uint128_t m			virtual map found counting
** __uint128_t cmask		current coords mask while iterating
*/
static unsigned int space_left(__uint128_t m, int const w)
{
	t_vec2i			c;
	__uint128_t		cmask[1];
	unsigned int	space;
	unsigned int	tmp;

	space = 0;
	c.y = 0;
	while (c.y < w)
	{
		*cmask = ((__uint128_t)1) << (11 * c.y);
		c.x = 0;
		while (c.x < w)
		{
			if ((m & *cmask) == 0)
			{
				tmp = follow(&m, w, cmask, c);
				/* qprintf("TMP %d\n", tmp); */
				if (tmp >= 4)
					space += tmp;
			}
			*cmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return space;
}

static bool		loop_coords3bis(__uint128_t const m, t_ppool *const pool
								, int const w
								, int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	__uint128_t				pmask;

	if (space_left(m, w) < (unsigned int)(pool->lastpid - pid + 1) * 4)
		return false;
	/* qprintf("TEST\n"); */
	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask128 << (11 * c.y);
		while (c.x <= w - p->w)
		{
			if (pid == 1)
				qprintf("%d %d\n", c.x, c.y);
			if ((pmask & m) == 0)
			{
				if (pid == pool->lastpid || loop_coords3bis(m | pmask, pool, w, pid + 1))
				{
					pool->pcs[pid].finalpos = c;
					return true;
				}
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return false;
}


/*
** Math function
*/
int			ft_sqrtfloor(int v)
{
	int		i;

	i = v;
	while (i * i > v)
		i--;
	return i;
}

int			ft_sqrtceil(int v)
{
	int		i;

	i = 0;
	while (i * i < v)
		i++;
	return i;
}

/*
** Loads loop_coords2's result to t_map
*/

void		write_map_solve2(t_map m, t_ppool *const pool)
{
	int				i;
	t_piece const	*p;
	int const		max = pool->lastpid + 1;

	for (i = 0 ; i < max; i++)
	{
		p = pool->pcs + i;
		m[p->dt[0].y + p->finalpos.y][p->dt[0].x + p->finalpos.x] = p->character;
		m[p->dt[1].y + p->finalpos.y][p->dt[1].x + p->finalpos.x] = p->character;
		m[p->dt[2].y + p->finalpos.y][p->dt[2].x + p->finalpos.x] = p->character;
		m[p->dt[3].y + p->finalpos.y][p->dt[3].x + p->finalpos.x] = p->character;
	}
	return ;
}

bool g_use_bitwise = true;

/*
** Tries succesive map size picking the right algorithm
*/
int 		loop_sizes(t_map m, t_ppool *const pool)
{
	int			w;

	w = ft_sqrtceil(pool->lastpid * 4 + 4);
	while (1)
	{
		/* if (w <= 8 && g_use_bitwise) */
		/* { */
		/* 	qprintf("%s with w=%d loop_coords2\n", __FUNCTION__, w); */
		/* 	if (loop_coords2(0, pool, w, 0)) */
		/* 	{ */
		/* 		g_use_bitwise = false; */
		/* 		write_map_solve2(m, pool); */
		/* 		break; */
		/* 	} */
		/* } */

		if (w <= 8 && g_use_bitwise)
		{
			/* qprintf("%s with w=%d loop_coords2\n", __FUNCTION__, w); */
			if (loop_coords2(0, pool, w, 0))
			{
				g_use_bitwise = false;
				write_map_solve2(m, pool);
				break;
			}
		}
		else if (w <= 11 && g_use_bitwise)
		{
			/* qprintf("%s with w=%d loop_coords3\n", __FUNCTION__, w); */
			if (loop_coords3(0, pool, w, 0))
			{
				g_use_bitwise = false;
				write_map_solve2(m, pool);
				break;
			}
		}
		else
		{
			/* qprintf("%s with w=%d loop_coords\n", __FUNCTION__, w); */
			if (loop_coords(m, pool, w, 0))
				break;
		}
		w++;
	}
	return w;
}

/*
** Builds t_map and prints result
*/
void		solver(t_ppool *pool)
{
	char		m[MAP_W][MAP_W];
	int			w;

	memset(m, '.', sizeof(m));

	w = loop_sizes(m, pool);

	int x, y;
	for (y = 0; y < w; y++)
	{
		for (x = 0; x < w; x++)
		{
			printf("%c", m[y][x]);
		}
		printf("\n");
	}
	return ;
}

t_piece const pcs[] = {
    {0, 0x10302, 0x401802, 2, 3, {{1, 0},{0, 1},{1, 1},{0, 2}}, {0, 0}, '\0'},
	{1, 0x702, 0x3802, 3, 2, {{1, 0},{0, 1},{1, 1},{2, 1}}, {0, 0}, '\0'},
	{2, 0x30202, 0xc01002, 2, 3, {{1, 0},{1, 1},{0, 2},{1, 2}}, {0, 0}, '\0'},
	{3, 0x20302, 0x801802, 2, 3, {{1, 0},{0, 1},{1, 1},{1, 2}}, {0, 0}, '\0'},
	{4, 0x306, 0x1806, 3, 2, {{1, 0},{2, 0},{0, 1},{1, 1}}, {0, 0}, '\0'},
	{5, 0x10301, 0x401801, 2, 3, {{0, 0},{0, 1},{1, 1},{0, 2}}, {0, 0}, '\0'},
	{6, 0x207, 0x1007, 3, 2, {{0, 0},{1, 0},{2, 0},{1, 1}}, {0, 0}, '\0'},
	{7, 0x701, 0x3801, 3, 2, {{0, 0},{0, 1},{1, 1},{2, 1}}, {0, 0}, '\0'},
	{8, 0x603, 0x3003, 3, 2, {{0, 0},{1, 0},{1, 1},{2, 1}}, {0, 0}, '\0'},
	{9, 0x1010101, 0x200400801, 1, 4, {{0, 0},{0, 1},{0, 2},{0, 3}}, {0, 0}, '\0'},
	{10, 0x10103, 0x400803, 2, 3, {{0, 0},{1, 0},{0, 1},{0, 2}}, {0, 0}, '\0'},
	{11, 0x407, 0x2007, 3, 2, {{0, 0},{1, 0},{2, 0},{2, 1}}, {0, 0}, '\0'},
	{12, 0x30101, 0xc00801, 2, 3, {{0, 0},{0, 1},{0, 2},{1, 2}}, {0, 0}, '\0'},
	{13, 0x303, 0x1803, 2, 2, {{0, 0},{1, 0},{0, 1},{1, 1}}, {0, 0}, '\0'},
	{14, 0x20203, 0x801003, 2, 3, {{0, 0},{1, 0},{1, 1},{1, 2}}, {0, 0}, '\0'},
	{15, 0x107, 0x807, 3, 2, {{0, 0},{1, 0},{2, 0},{0, 1}}, {0, 0}, '\0'},
	{16, 0x704, 0x3804, 3, 2, {{2, 0},{0, 1},{1, 1},{2, 1}}, {0, 0}, '\0'},
	{17, 0x20301, 0x801801, 2, 3, {{0, 0},{0, 1},{1, 1},{1, 2}}, {0, 0}, '\0'},
	{18, 0xf, 0xf, 4, 1, {{0, 0},{1, 0},{2, 0},{3, 0}}, {0, 0}, '\0'},
};

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
  3 4.000000
  4 4.000000
  5 5.000000
  6 5.000000
  7 6.000000
  8 6.000000
  9 6.000000
  10 7.000000		EASY
  11 7.000000
  12 7.000000		HARD
  13 8.000000		EASY
  14 8.000000
  15 8.000000
  16 8.000000		HARD
  17 9.000000		EASY
  18 9.000000
  19 9.000000
  20 9.000000		HARD
  21 10.000000	EASY
  22 10.000000
  23 10.000000
  24 10.000000
  25 10.000000	HARD
  26 11.000000	EASY
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


bool charsValid(char const buf[(4 + 1) * 4])
{
	int sharp_count;

	sharp_count = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (buf[y * 5 + x] == '#')
				sharp_count++;
			else if (buf[y * 5 + x] != '.')
				return (qprintf("FAILED LINE %d", __LINE__), false);
		}
		if (buf[y * 5 + 4] != '\n')
			return (qprintf("FAILED LINE %d", __LINE__), false);
	}
	if (sharp_count != 4)
		return (qprintf("FAILED LINE %d", __LINE__), false);
	return true;
}

unsigned int adjDiff(char const val[(4 + 1) * 4])
{
	unsigned int    acc = 0;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 3; x++)
			if (val[y * 5 + x] == '#' && val[y * 5 + x + 1] == '#')
				acc++;
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 4; x++)
			if (val[y * 5 + x] == '#' && val[(y + 1) * 5 + x] == '#')
				acc++;
	return acc;
}

# define SIZE_ARRAY(A) (sizeof((A)) / sizeof(*(A)))
# define STRIDE_ARRAY(A) (sizeof(*(A)))
# define END_ARRAY(A) ((void*)(A) + sizeof((A)))
# define MAX(V1, V2) ((V1) > (V2) ? V1 : V2)
# define MIN(V1, V2) ((V1) < (V2) ? V1 : V2)

bool match_piece(char const val[(4 + 1) * 4], t_piece const *pc, t_vec2i tl)
{
	int x, y;

	for (int dt = 0; dt < 4; dt++)
	{
		y = tl.y + pc->dt[dt].y;
		x = tl.x + pc->dt[dt].x;
		if (x >= 4 || y >= 4 || val[y * 5 + x] != '#')
			return false;
	}
	return true;
}

t_vec2i calc_top_left(char const val[(4 + 1) * 4])
{
	int minx, miny;

	minx = 4;
	miny = 4;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (val[y * 5 + x] == '#')
			{
				minx = MIN(x, minx);
				miny = MIN(y, miny);
			}
		}
	}
	return (t_vec2i){minx, miny};
}

void save_piece(char const val[(4 + 1) * 4], t_ppool p[1])
{
	t_piece const *pc = pcs;
	t_vec2i const topleft = calc_top_left(val);

	while ((void*)pc < END_ARRAY(pcs))
	{
		if (match_piece(val, pc, topleft))
		{
			p->pcs[p->lastpid] = *pc;
			return ;
		}
		pc++;
	}
	qprintf("FAILED LINE %d", __LINE__);
	return ;
}

int parser(char const *fname, t_ppool p[1])
{
	int const fd = open(fname, O_RDONLY);
	char buf1[(4 + 1) * 4];
	char buf2[1];
	int ret;
	int i;

	i = 0;
	while ((ret = read(fd, buf1 + i, sizeof(buf1) - i)) > 0)
	{
		i += ret;
		if (i == sizeof(buf1))
		{
			if (!charsValid(buf1) || adjDiff(buf1) < 3)
				return (qprintf("FAILED LINE %d", __LINE__), 1);
			save_piece(buf1, p);
			p->lastpid++;
			/* qprintf("SAVING\n"); */
			ret = read(fd, buf2, 1);
			if (ret == 0)
				break ;
			else if (ret < 0 || *buf2 != '\n')
				return (qprintf("FAILED LINE %d", __LINE__), 1);
			i = 0;
		}
	}
	p->lastpid--;
	close(fd);
	return (0);
}

int							main(int ac, char *av[])
{
	t_ppool		pool;
	int			i;
	int const	max_rand = 1;

	bzero(&pool, sizeof(pool)); //debug
	if (ac < 2)
	{
		srand(time(0));
		/* srand(1); */
		for (i = 0; i < max_rand; i++)
			pool.pcs[i] = pcs[rand() % sizeof(pcs) / sizeof(*pcs)];
		pool.lastpid = max_rand - 1;
	}
	else
	{
		if (parser(av[1], &pool))
			return (1);
	}
	for (i = 'A'; i <= 'Z'; i++)
		pool.pcs[i - 'A'].character = i;

	clock_t p1;

	p1 = clock();
	solver(&pool);
	/* printf("%.6f\n", ((double)(clock() - p1)) / (double)CLOCKS_PER_SEC); */

	/* p1 = clock(); */
	/* solver(&pool); */
	/* printf("%.6f\n", ((double)(clock() - p1)) / (double)CLOCKS_PER_SEC); */
	return (0);
}
