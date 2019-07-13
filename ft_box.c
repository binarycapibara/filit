/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/13 20:56:46 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	(1)void	ft_p_a(int m, char min_box[m][m])
**	Function to print min_box
** **************************************************************************
*/

void		ft_p_a(int m, char min_box[m][m])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < m)
	{
		j = 0;
		while (j < m)
		{
			ft_putchar(min_box[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

/*
** **************************************************************************
**	(2)int	ft_box_size(int n)
**	Function count size of minimum possible box. N = 26 >>> m = 11
** -------------------------------------------------------------------------
**	----Test print for ft_box_size (n [0..26])----
**	nbr = -1;
**	while (nbr++ < 26)
**	{
**		i = ft_box_size(nbr);
**		printf("N=%d box(%d * %d) \n", nbr, i, i);
**	}
** **************************************************************************
*/

int			ft_box_size(int n)
{
	int		m;
	int		tmp;

	m = 1;
	tmp = 0;
	while (tmp < n * 4)
	{
		tmp = m * m;
		m++;
	}
	return (m - 1);
}

/*
** **************************************************************************
**	(3)int	ft_box_in(int m, char min_box[m][m])
**	Function place shapes in min_box
**	for create bigger min_box place ft_box_create(m++, all_sh);
**	size - number of shapes
** **************************************************************************
*/

int			ft_tile_box(int size, int m, char min_box[m][m], t_crds *all_sh)
{
	int		i;
	int		j;
	int		sh_nb;

	i = 0;
	j = 0;
	sh_nb = 0;
	while (sh_nb < size)
	{
		all_sh[sh_nb].mb_x = 0;
		all_sh[sh_nb].mb_y = 0;
		if (ft_plc_sh(m, min_box, sh_nb, all_sh))
			sh_nb++;
		else
			break ;
	}
	//ft_p_a(m, min_box);
	if (sh_nb != size)
		return(0);
	return (1);
}

/*
** **************************************************************************
**	(4)int	ft_box_create(int m, t_tetris *all_sh)
**	Function create array min_box for handle our shapes.
**	Array initialized with '.' then send in to ft_box_in then printed
** **************************************************************************
*/

int		ft_box_create(int sh_nb, int m, t_crds *all_sh)
{
	char	min_box[m][m];
	int		i;
	int		j;

	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < m)
		{
			min_box[i][j] = '.';
			j++;
		}
		i++;
	}
	if (!ft_tile_box(sh_nb, m, min_box, all_sh))
	{
		ft_box_create(sh_nb, m + 1, all_sh);
	}
	else
	{
		ft_p_a(m, min_box);
	}
	return (0);
}

/*
** **************************************************************************
**	(5)int	ft_box(int n)
**	Function for send m to ft_box_create for create min_box
** **************************************************************************
*/

int			ft_box(int sh_nb, t_crds *all_sh)
{
	int		m;

	m = ft_box_size(sh_nb);
	ft_box_create(sh_nb, m, all_sh);
	return (0);
}
