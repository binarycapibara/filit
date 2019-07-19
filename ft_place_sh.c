/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:26:09 by drafe             #+#    #+#             */
/*   Updated: 2019/07/19 19:38:24 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			ft_mb_chk(int m, char **min_box, int sh_nb, t_crds *all_sh)
{
	int		p_nb;
	int		tmp;
	int		x;
	int		y;

	p_nb = 0;
	tmp = 0;
	x = 0;
	y = 0;
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

int			ft_sh_move(int m, char **min_box, int sh_nb, t_crds *all_sh)
{
	int		chk;

	chk = 0;
	while (!chk && (all_sh[sh_nb].mb_y < m))
		chk = ft_mb_chk(m, min_box, sh_nb, all_sh);
	if (chk)
		return (1);
	return (0);
}

int			ft_plc_sh(int m, char **min_box, int sh_nb, t_crds *all_sh)
{
	int		p_nb;

	p_nb = 0;
	if (ft_sh_move(m, min_box, sh_nb, all_sh))
	{
		while (p_nb < 4)
		{
			min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
			[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] = all_sh[sh_nb].sh_let;
			p_nb++;
		}
		return (1);
	}
	else
	{
		all_sh[sh_nb].mb_x = 0;
		all_sh[sh_nb].mb_y = 0;
		return (0);
	}
}

void		ft_rm_sh(char **min_box, int sh_nb, t_crds *all_sh)
{
	int		p_nb;
	int		x;
	int		y;

	p_nb = 0;
	x = 0;
	y = 0;
	if (sh_nb < 0)
		sh_nb = 0;
	while (p_nb < 4)
	{
		y = all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb];
		x = all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb];
		if (all_sh[sh_nb].sh_let == min_box[y][x])
			min_box[y][x] = '.';
		p_nb++;
	}
}
