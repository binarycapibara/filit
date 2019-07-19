/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/19 20:20:02 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_p_a(int m, char **min_box)
{
	int			i;

	i = 0;
	while (i < m)
	{
		ft_putstr(min_box[i]);
		ft_putstr("\n");
		i++;
	}
}

int				ft_box_size(int n)
{
	int			m;
	int			tmp;

	m = 1;
	tmp = 0;
	while (tmp < n * 4)
	{
		tmp = m * m;
		m++;
	}
	return (m - 1);
}

char			**ft_box_create(int m)
{
	char		**min_box;
	int			i;
	int			j;

	i = 0;
	if (!(min_box = (char**)malloc(sizeof(char*) * m)))
		return (0);
	while (i < m)
	{
		j = 0;
		if (!(min_box[i] = (char*)malloc(sizeof(char) * m)))
			return (0);
		while (j < m)
		{
			min_box[i][j] = '.';
			j++;
		}
		i++;
	}
	return (min_box);
}

int				ft_tile(char **min_box, int n, t_crds *all_sh, int pos)
{
	int			m;
	int			x;
	int			y;

	m = 0;
	y = 0;
	if (pos >= n)
		return (1);
	m = ft_box_size(n);
	while (y < m)
	{
		x = -1;
		while (++x < m)
		{
			all_sh[pos].mb_x = x;
			all_sh[pos].mb_y = y;
			if (ft_plc_sh(m, min_box, pos, all_sh) \
			&& ft_tile(min_box, n, all_sh, pos + 1))
				return (1);
			else
				ft_rm_sh(min_box, pos, all_sh);
		}
		y++;
	}
	return (0);
}

int				ft_box(int sh_nb, t_crds *all_sh)
{
	char		**min_box;
	int			m;

	m = ft_box_size(sh_nb);
	min_box = ft_box_create(m);
	while (!ft_tile(min_box, sh_nb, all_sh, 0))
		m++;
	ft_p_a(m, min_box);
	return (1);
}
