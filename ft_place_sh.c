/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:26:09 by drafe             #+#    #+#             */
/*   Updated: 2019/07/13 19:47:54 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	(1) int	ft_f_offset(int p_nb)
**	Function move shape to next + 1 point
** **************************************************************************
*/

int			ft_p_offset(int m, int p_nb, int sh_nb, t_crds *all_sh)
{
	if (p_nb != 4)
	{
		if (all_sh[sh_nb].mb_x >= m)
		{
			all_sh[sh_nb].mb_x = 0;
			all_sh[sh_nb].mb_y += 1;
		}
		else
			all_sh[sh_nb].mb_x += 1;
		return (0);
	}
	else
		return (1);
}

/*
** **************************************************************************
**	(2)int	ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_crds *all_sh)
**	Function to check correct place of shape in min_box
** **************************************************************************
*/

int			ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_crds *all_sh)
{
	int		p_nb;
	int		tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p_nb = 0;
	tmp = 0;
	while (p_nb < 4)
	{
		x = all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb];
		y = all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb];
		if (((x >= m) || (y >= m)) || (min_box[y][x] != '.') || (tmp < 0))
			break ;
		tmp = x;
		p_nb++;
	}
	return (ft_p_offset(m, p_nb, sh_nb, all_sh));
}

/*
** **************************************************************************
**	(3)int	ft_p_move(int m, char min_box[m][m], int sh_nb, t_crds *all_sh)
**	Function to move shape through min_box
**	check all shape points fit in or not
** **************************************************************************
*/

int			ft_sh_move(int m, char min_box[m][m], int sh_nb, t_crds *all_sh)
{
	int		chk;

	chk = 0;
	while (!chk && (all_sh[sh_nb].mb_y < m))
	{
		chk = ft_mb_chk(m, min_box, sh_nb, all_sh);
	}
	if (chk)
		return (1);
	return (0);
}

/*
** **************************************************************************
**	(4)int ft_sh_in(int m, char min_box[m][m])
**	Function place one shape in min_box if ft_p_move == 1
** **************************************************************************
*/

int			ft_plc_sh(int m, char min_box[m][m], int sh_nb, t_crds *all_sh)
{
	int		p_nb;

	p_nb = 0;
	if (ft_sh_move(m, min_box, sh_nb, all_sh))
	{
		
		while (p_nb < 4)
		{
			all_sh[sh_nb].used = 1;
			min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
			[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] = all_sh[sh_nb].sh_let;
			p_nb++;
		}
		return (1);
	}
	else
	{
		all_sh[sh_nb].used = 0;
		return (0);
	}
}
