/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:27:22 by drafe             #+#    #+#             */
/*   Updated: 2019/07/22 01:53:56 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_x_c(char *s, int i)
{
	int	res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	res = res % 5;
	if ((res < 5) && (res > 1))
		res = res - 5;
	return (res);
}

static int	ft_y_c(char *s, int i)
{
	int		res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	if (res < 3)
		res = 0;
	else
		res = 1;
	return (res);
}

static void	ft_save_shape_var_init(t_ft_save_shape_holder *var)
{
	var->i = -1;
	var->sh_nb = 0;
	var->nl_nb = 0;
	var->p_n = 0;
}

static void	ft_save_shape_ext(t_tet *all_sh, t_ft_save_shape_holder *var)
{
	var->nl_nb++;
	if ((var->nl_nb % 5 == 0) && (var->nl_nb != 0))
	{
		all_sh[var->sh_nb].litera = 'A' + var->sh_nb;
		var->sh_nb++;
		var->nl_nb = 0;
		var->p_n = 0;
	}
}

int			ft_save_shape(char *s, t_tet *a)
{
	t_ft_save_shape_holder	v;

	ft_save_shape_var_init(&v);
	while (s[++v.i] != '\0')
	{
		if (s[v.i] == '#')
		{
			if (v.p_n == 0)
			{
				a[v.sh_nb].x[v.p_n] = 0;
				a[v.sh_nb].y[v.p_n] = 0;
			}
			else
			{
				a[v.sh_nb].x[v.p_n] = a[v.sh_nb].x[v.p_n - 1] + ft_x_c(s, v.i);
				a[v.sh_nb].y[v.p_n] = a[v.sh_nb].y[v.p_n - 1] + ft_y_c(s, v.i);
			}
			v.p_n++;
		}
		if (s[v.i] == '\n')
			ft_save_shape_ext(a, &v);
	}
	a[v.sh_nb].litera = 'A' + v.sh_nb;
	ft_strdel(&s);
	return (v.sh_nb);
}
