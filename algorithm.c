/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/08 20:59:12 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_box_calc(int	**N)  //, char		**box)
{
	int		res;

	// res = **N;
	// printf("%d\n", res);
	// printf("\n-------------------------------------------");
	// res = res * 4;
	// res = ft_sqrt(res);
	// // *N = res;
	// printf("%d\n", res);

	// **N = res;
	// // box[0][0] = 'A';
	// // return ;
	(**N == 1) ? res = 2 : 0;
	(**N == 2) ? res = 3 : 0;
	(**N == 3) ? res = 4 : 0;
	(**N == 4) ? res = 4 : 0;
	(**N == 5) ? res = 5 : 0;
	(**N == 6) ? res = 5 : 0;
	(**N == 7) ? res = 6 : 0;
	(**N == 8) ? res = 6 : 0;
	(**N == 9) ? res = 6 : 0;
	(**N == 10) ? res = 7 : 0;
	(**N == 11) ? res = 7 : 0;
	(**N == 12) ? res = 7 : 0;
	(**N == 13) ? res = 8 : 0;
	(**N == 14) ? res = 8 : 0;
	(**N == 15) ? res = 8 : 0;
	(**N == 16) ? res = 8 : 0;
	(**N == 17) ? res = 9 : 0;
	(**N == 18) ? res = 9 : 0;
	(**N == 19) ? res = 9 : 0;
	(**N == 20) ? res = 9 : 0;
	(**N == 21) ? res = 10 : 0;
	(**N == 22) ? res = 10 : 0;
	(**N == 23) ? res = 10 : 0;
	(**N == 24) ? res = 10 : 0;
	(**N == 25) ? res = 10 : 0;
	(**N == 26) ? res = 11 : 0;
	return (res);
}

static	char	**ft_get_min_box(int	size)
{
char	box[3][3];
int		i;
int		j;

i = 0;
j = 0;

while (j != (3 + 1))
	{
		while (i != (3 + 1))
		{
			box[j][i] = '.';
			i++;
		}
	j++;
	}
return (box);
}



void ft_algo(int	*N, t_tetris *sh_coord)
{
	int			sh_nb;
	int			i;
	int			k;
	char		***box;
	int			size;
	int			m;
	int			n;
	char		**box;

	sh_nb = 0;
	k = *N;
	box = NULL;
	printf("%d\n", k);
 	while (sh_nb <= *N)
	{
		i = 0;
		printf("\n***vvv***%d***vvv***", sh_nb);
		while (i < 4)
		{
			printf("\nt[%d].x[%d]=%d  y[%d]=%d", sh_nb, i, sh_coord[sh_nb].x[i], i, sh_coord[sh_nb].y[i]);
			i++;
		}
		sh_nb++;
	}
	printf("\n-------------------------------------------");
	size = ft_box_calc(&N);//, *box);
	printf("%d\n", *N);
	printf("%d\n", size);
	box = ft_get_min_box(size);
	m = 0;
	n = 0;
	while (m != (size + 1))
	{
		while (n != (size + 1))
		{
			printf("%s", box[m][n]);
			n++;
		}
		printf("\n");
		m++;
	}	
}