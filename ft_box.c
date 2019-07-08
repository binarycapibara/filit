/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 15:02:06 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_box_size(int n)
{
	int		m;
	int		tmp;

	m = 1;
	tmp = 0;
	while (tmp < n * 4)
	{
		tmp = m * m;
		m++;
	}
	return (m - 1);
}

int			ft_box(int sh_nb, t_tetris *all_sh)
{
	int		i;
	int		nbr;

	i =	0;
	nbr = all_sh[0].x[0] + sh_nb;
	nbr = -1;
	while (nbr++ < 26)
	{
		i = ft_box_size(nbr);
		printf("N=%d box(%d * %d) \n", nbr, i, i);
	}
// Если √a = b , то b*b=a,   
	return (0);
}
