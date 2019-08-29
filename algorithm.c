/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/22 15:46:36 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_minbox_init(t_ft_get_min_box_holder *var)
{
	var->m = -1;
	var->n = -1;
}

char			**ft_get_min_box(int size)
{
	t_ft_get_min_box_holder	var;

	ft_minbox_init(&var);
	if (!(var.box = (char **)malloc(sizeof(char*) * size)))
	{
		ft_putstr("error\n");
		exit(1);
	}
	while (++var.m != size)
	{
		if (!(var.box[var.m] = (char *)malloc(sizeof(char *) * (size - 1))))
		{
			while (--var.m)
				free(var.box[var.m]);
			free(var.box);
			ft_putstr("error\n");
			exit(1);
		}
		while (++var.n != size)
			var.box[var.m][var.n] = '.';
		var.n = -1;
	}
	return (var.box);
}

static	void	ft_reposition_coord_neg(t_tet *sh_co, int *num)
{
	t_ft_reposition_coord_neg	v;

	v.sh_nb = 0;
	v.p_nb = 0;
	v.num = *num;
	while (++v.sh_nb != (v.num + 1))
	{
		while (++v.p_nb != 4)
		{
			if (sh_co[v.sh_nb].x[v.p_nb] < 0)
			{
				v.te = sh_co[v.sh_nb].x[v.p_nb];
				v.te = (v.te * (-1));
				v.p_nb = 0;
				while (v.p_nb != 4)
				{
					sh_co[v.sh_nb].x[v.p_nb] = sh_co[v.sh_nb].x[v.p_nb] + v.te;
					v.p_nb++;
				}
				v.p_nb = 0;
			}
		}
		v.p_nb = 0;
	}
}

void			ft_algo(int num, t_tet *sh_coord)
{
	int		sh_nb;
	char	sequence[num];
	t_kvars	dimension;

	dimension.size = 2;
	dimension.num = num + 1;
	dimension.box = ft_get_min_box(26);
	ft_memset(sequence, 0, sizeof(sequence));
	sh_nb = 0;
	while (sh_nb <= num)
	{
		sequence[sh_nb] = sh_coord[sh_nb].litera;
		sh_nb++;
	}
	ft_reposition_coord_neg(sh_coord, &num);
	worker(sh_coord, &dimension, sequence);
}
