/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_touch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/08/06 16:44:43 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_variables_init(t_ft_valid_touch_holder *var)
{
	var->i = -1;
	var->p_nb = 0;
	var->touch_sum = 0;
	var->sh_touch = 0;
}

static	int		ft_sh_touch(char *s, int i)
{
	int	sh_touch;
	int	off_s;

	sh_touch = 0;
	off_s = 0;
	while (((i - off_s - 1) != 0) && (off_s < 6))
		if ((s[i - off_s] == '\n') && (s[i - off_s - 1] == '\n'))
			break ;
		else
			off_s++;
	if ((s[i - 5] == '#') && (off_s > 3))
		sh_touch++;
	off_s = 0;
	while ((s[i + off_s + 1] != '\0') && (off_s < 6))
		if ((s[i + off_s] == '\n') && (s[i + off_s + 1] == '\n'))
			break ;
		else
			off_s++;
	if ((s[i + 5] == '#') && (off_s > 5))
		sh_touch++;
	if (s[i + 1] == '#')
		sh_touch++;
	if (s[i - 1] == '#')
		sh_touch++;
	return (sh_touch);
}

int				ft_sh_size(char *s)
{
	t_ft_valid_touch_holder	var;

	ft_variables_init(&var);
	while (s[++var.i] != '\0')
	{
		if (s[var.i] == '#')
		{
			var.sh_touch = ft_sh_touch(s, var.i);
			if ((var.sh_touch == 0) || (var.sh_touch > 4))
				return (0);
			var.p_nb++;
			var.touch_sum += var.sh_touch;
			var.sh_touch = 0;
		}
		if (var.p_nb == 4)
		{
			if ((var.touch_sum > 9) || (var.touch_sum < 5))
				return (0);
			var.touch_sum = 0;
			var.p_nb = 0;
		}
	}
	return (1);
}
