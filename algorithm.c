/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/07 22:03:37 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_box_calc(int	**N, char		**box)
{
	int		res;
	
	box[0][0] = 1;
	res = &N;
	res = ft_sqrt(res * 4);
	*N = res;
	// return ;
}

void ft_core_algo(int	**N, t_tetris *sh_coord)
{
	char		box[0][0];

	*sh_coord->x = 1;
	*sh_coord->y = 1;
	box[0][0] = 'A';
	ft_box_calc(&N, &box);
	ft_putnbr(*N);
	// return ;
}