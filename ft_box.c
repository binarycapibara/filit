/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 15:17:29 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* **************************************************************************
**	----int	ft_box_size(int n)----
**	Function count size of minimum possible box. N= 26 box(11 * 11)
** -------------------------------------------------------------------------
**	----Test print ft_box_size (n [0..26])----
**	nbr = -1; 
**	while (nbr++ < 26)
**	{
**		i = ft_box_size(nbr);
**		printf("N=%d box(%d * %d) \n", nbr, i, i);
**	}
** **************************************************************************
*/

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
	char	min_box[ft_box_size(sh_nb)][ft_box_size(sh_nb)];
	int		i;
	int		nbr;

	i =	0;
	nbr = all_sh[0].x[0]; 
	nbr = ft_box_size(sh_nb);
	//printf("%d * %d", nbr, nbr);
	min_box[0][0] = '\0';
	return (0);
}
