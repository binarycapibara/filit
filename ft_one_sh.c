/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/10 15:41:11 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	----int	ft_f_offset(int p_nb)----
** **************************************************************************
*/

int			ft_f_offset(int p_nb)
{
	if (p_nb < 4)
		return (1);
	else
		return (0);
}

/*
** **************************************************************************
**	----int ft_one_sh(int m, char min_box[m][m])----
**	Function correctly place one shape in min_box
** **************************************************************************
*/

int			ft_one_sh(int m, char min_box[m][m], int i, t_coords *all_sh)
{
	char	sh_letter;
	int		p_offset;
	int		p_nb;

	p_nb = 0;
	p_offset = 0;
	sh_letter = 'A' + i;
	while (p_nb < 4)
	{
		if (min_box[i + all_sh[i].y[p_nb]][i + all_sh[i].x[p_nb]] != '.')
			break ;
		else
			p_nb++;
	}
	p_offset = ft_f_offset(p_nb);
	p_nb = 0;
	while (p_nb < 4)
	{
		min_box[i + all_sh[i].y[p_nb]][i + p_offset \
		+ all_sh[i].x[p_nb]] = sh_letter;
		p_nb++;
	}
	return (1);
}
