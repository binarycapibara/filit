/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/09 18:04:12 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* **************************************************************************
**	----int ft_one_sh(int m, char min_box[m][m])----
**	Function correctly place one shape in min_box
** **************************************************************************
*/

int			ft_one_sh(int m, char min_box[m][m], int i, char sh_letter, t_coords *all_sh)
{
	int		p_nb;

	p_nb = 0;
	while (p_nb < 4)
	{
		if (min_box[i + all_sh[i].y[p_nb]][i + all_sh[i].x[p_nb]] != '.')
			return (0);
		else
			p_nb++;
	}
	p_nb = 0;
	while (p_nb < 4)
	{
		min_box[i + all_sh[i].y[p_nb]][i + all_sh[i].x[p_nb]] = sh_letter;
		p_nb++;
	}
	return (1);
}

/* **************************************************************************
**	----int ft_box_in(int m, char min_box[m][m])----
**	Function place shapes in min_box
** **************************************************************************
*/

int			ft_box_in(int m, char min_box[m][m], t_coords *all_sh)
{
	char	sh_letter;
	int		i;
	int		j;
	

	i = 0;
	j = 0;
	sh_letter = 'A';
	while (j < m)
	{
		if(ft_one_sh(m, min_box, j, sh_letter, all_sh))
		{
			sh_letter++;
		}
		j++;
	}
	//ft_box_create(m++, all_sh);
	return (0);
}

/* **************************************************************************
**	----int	ft_box_size(int n)----
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

/* **************************************************************************
**	----int	ft_box_create(int m, t_tetris *all_sh)----
**	Function create array min_box for handle our shapes.
**	Array initialized with '.'
** **************************************************************************
*/

int	ft_box_create(int m, t_coords *all_sh)
{
	char	min_box[m][m];
	int		i;
	int		j;

	i =	0;
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
	ft_box_in(m, min_box, all_sh);
	i =	0;
	while (i < m)
	{
		j = 0;
		while (j < m)
		{
			printf ("%c", min_box[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	return (0);
}

/* **************************************************************************
**	----int	ft_box(int n)----
**	Function for send m to 
** **************************************************************************
*/

int			ft_box(int sh_nb, t_coords *all_sh)
{
	int		m;

	m = all_sh[0].x[0]; 
	m = ft_box_size(sh_nb);
	ft_box_create(m, all_sh);
	//printf("%d * %d", nbr, nbr);
	return (0);
}
