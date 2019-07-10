/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/10 18:42:16 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	----int	ft_f_offset(int p_nb)----
** **************************************************************************
*/

int			ft_p_offset(int p_nb)
{
	if (p_nb != 0)
		return (1);
	else
		return (0);
}

/*
** **************************************************************************
**	----int ft_sh_in(int m, char min_box[m][m])----
**	Function correctly place one shape in min_box
** **************************************************************************
*/

int			ft_sh_in(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	char	sh_letter;
	int		p_offset;
	int		p_nb;

	p_nb = 0;
	p_offset = 0;
	sh_letter = 'A' + sh_nb;
/*	while (p_nb < 4)
	{
		if (min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
		[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] != '.')
			break ;
		else
			p_nb++;
	}
	p_nb = 0;
	all_sh[sh_nb].mb_x += ft_p_offset(p_nb);
*/
	all_sh[sh_nb].mb_x += 1;
	all_sh[sh_nb].mb_y += 1;
	while (p_nb < 4)
	{
		min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
		[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] = sh_letter;
		p_nb++;
	}
	return (1);
}
