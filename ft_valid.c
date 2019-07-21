/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/22 01:23:48 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_figure_count(char *s)
{
	int				shp;
	int				p_nb;
	int				i;

	shp = 0;
	p_nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			p_nb++;
		if (p_nb == 4)
		{
			shp++;
			p_nb = 0;
		}
		i++;
	}
	if (shp > 26)
		return (0);
	else
		return (1);
}

int			ft_symb_chk(char *s)
{
	t_ft_symb_check_holder	var;

	var.i = 0;
	var.p_nb = 0;
	var.tetr_l = 1;
	var.n_of_ns = 0;
	while (s[var.i] != '\0')
	{
		if (s[var.i] == '#')
			var.p_nb++;
		if (s[var.i] == '\n')
			var.n_of_ns++;
		if (s[var.i] == '\n' && s[var.i + 5] == '\n')
			var.tetr_l++;
		if ((var.p_nb % 4 != 0) && (var.tetr_l % 4 != 0) && (s[var.i] == '\0'))
			return (0);
		var.i++;
	}
	if ((((var.tetr_l / 4) * 5) - 1) < var.n_of_ns)
		return (0);
	return (1);
}

int			ft_nl_chk(char *s)
{
	int		i;
	int		m;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.' || s[i] == '#' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	i = 1;
	m = 0;
	while (s[i] != '\0')
	{
		if ((i - m) % 20 == 0)
		{
			if (s[i - m] == '\n' || s[i - m] == '\0')
				m++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_shp_chk(char *s)
{
	int		i;
	int		p_nb;

	i = 0;
	p_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			p_nb++;
		if ((s[i] == '\n') && ((s[i + 1] == '\0') || (s[i + 1] == '\n')))
		{
			if (p_nb != 4)
				return (0);
			p_nb = 0;
		}
		i++;
	}
	return (1);
}

int			ft_valid(char *s)
{
	if (!ft_nl_chk(s))
		return (0);
	if (!ft_symb_chk(s))
		return (0);
	if (!ft_shp_chk(s))
		return (0);
	if (!ft_sh_size(s))
		return (0);
	if (!ft_figure_count(s))
		return (0);
	return (1);
}
