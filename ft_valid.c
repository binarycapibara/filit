/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:58:00 by drafe             #+#    #+#             */
/*   Updated: 2019/07/20 17:20:24 by drafe            ###   ########.fr       */
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

	tmp = (n_sh * 5) - 1;
	nl_nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			nl_nb++;
		i++;
	}
	if ((nl_nb != tmp) || (i < ((n_sh * 21) - 1)))
		return (0);
	return (1);
}

int			ft_shp_chk(char *s)
{
	int		i;
	int		p_nb;
	int		diag;

	i = -1;
	diag = 0;
	p_nb = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '#')
		{
			if ((s[i + 3] == '#') || (s[i + 5] == '#'))
				diag++;
			else
				diag = 0;
			p_nb++;
		}
		if ((s[i] == '\n') && ((s[i + 1] == '\0') || (s[i + 1] == '\n')))
		{
			if (p_nb != 4 || (diag == 4))
				return (0);
			p_nb = 0;
		}
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
	ft_lstbzero(all_shapes, n_sh);
	return (ft_box(ft_save_shape(s, all_shapes), all_shapes));
}
