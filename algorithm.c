/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/08 17:53:50 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_box_calc(int	**N)  //, char		**box)
{
	int		res;

	res = *N;
	res = res * 4;
	// res = ft_sqrt(res);
	// *N = res;
	printf("%d", res);
	// box[0][0] = 'A';
	// return ;
}

void ft_algo(int	*N, t_tetris *sh_coord)
{
	int			sh_nb;
	int			i;
	int			k;
	char		***box;

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
	ft_box_calc(&N);//, *box);
	printf("%p\n", N);
}