/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:58:00 by drafe             #+#    #+#             */
/*   Updated: 2019/07/20 22:36:17 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_symb_chk(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '#' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_nl_chk(char *s, int n_sh)
{
	int		nl_nb;
	int		tmp;
	int		i;
	int		shp;

	return (1);
	tmp = (n_sh * 5) - 1;
	nl_nb = 0;
	i = 0;
	shp = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			printf("i=%d shp=%d sum=%d\n", i, shp,i % (19 + shp));
			if ((i % (19 + shp)) == 0)
				shp++;
			nl_nb++;
		}
		i++;
	}
	//printf("i=%d", i);
	if ((nl_nb != tmp) || (shp != n_sh) \
	|| ((i < ((n_sh * 21) - 1))) || ((i > ((n_sh * 21) - 1))))
		return (0);

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

int			ft_sh_size(char *s)
{
	int		i;
	int		p_nb;
	int		sh_touch;
	int		touch_sum;

	i = 0;
	p_nb = 0;
	touch_sum = 0;
	sh_touch = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#') 
				sh_touch++;
			if(s[i + 5] == '#')
				sh_touch++;
			if (s[i - 1] == '#')
				sh_touch++;
			if(s[i - 5] == '#')
				sh_touch++;
			if ((sh_touch == 0) || (sh_touch > 4))
				return (0);
			p_nb++;
			//printf("i=%d sh_touch=%d p_nb=%d\n", i, sh_touch, p_nb);
			touch_sum += sh_touch;
			sh_touch = 0;
		}
		if (p_nb == 4)
		{
			if ((touch_sum > 9) || (touch_sum < 5))
				return (0);
			touch_sum = 0;
			p_nb = 0;
		}
		i++;
	}
	return (1);
}

int			ft_valid(char *s, int n_sh)
{
	t_crds	all_shapes[n_sh];

	if (!ft_nl_chk(s, n_sh))
		return (0);
	if (!ft_symb_chk(s))
		return (0);
	if (!ft_shp_chk(s))
		return (0);
	if (!ft_sh_size(s))
		return (0);
	ft_lstbzero(all_shapes, n_sh);
	return (ft_box(ft_save_shape(s, all_shapes), all_shapes));
}
