/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:27:22 by drafe             #+#    #+#             */
/*   Updated: 2019/07/20 20:58:35 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_x_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	res = res % 5;
	if ((res < 5) && (res > 1))
		res = res - 5;
	return (res);
}

int					ft_y_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	if (res < 3)
		res = 0;
	else
		res = 1;
	return (res);
}

int					ft_save_shape(char *s, t_crds *all_sh)
{
	int				p_nb;
	int				shp;
	int				i;

	i = -1;
	shp = 0;
	p_nb = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '#')
		{
			if (p_nb != 0)
			{
				all_sh[shp].x[p_nb] = all_sh[shp].x[p_nb - 1] + ft_x_c(s, i);
				all_sh[shp].y[p_nb] = all_sh[shp].y[p_nb - 1] + ft_y_c(s, i);
			}
			p_nb++;
		}
		if (p_nb == 4)
		{
			shp++;
			p_nb = 0;
		}
	}
	return (shp);
}
