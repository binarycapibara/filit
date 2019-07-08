/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/08 16:12:42 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static void		ft_box_calc(int	*N, char		*box)
// {
// 	int		res;
	
// 	res = &N;
// 	res = ft_sqrt(res * 4);
// 	*N = res;
// 	// return ;
// }

void ft_algo(int	*N, t_tetris *sh_coord)
{
	int			sh_nb;
	int			i;
	int			k;

	sh_nb = 0;
	k = *N;
	printf("%d\n", k);
 	while (sh_nb <= k)
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
	// *sh_coord->x = 1;
	// *sh_coord->y = 1;
	// box[0][0] = 'A';
	// ft_box_calc(&N, &box);
	// ft_putnbr(*N);
	// return ;
}