/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/10 20:47:13 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			printf("%c", min_box[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/*
** **************************************************************************
**	-int	ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)-
**	Function to check correct place of shape in min_box
** **************************************************************************
*/

int			ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	int		p_nb;

	p_nb = 0;
	while (p_nb < 4)
	{
		if (min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
		[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] != '.')
			break ;
		p_nb++;
	}
	if (ft_p_offset(p_nb))
	{
		all_sh[sh_nb].mb_x += ft_p_offset(p_nb);
		ft_sh_in(m, min_box, sh_nb, all_sh);
	}
	if (all_sh[sh_nb].mb_x >= m)
	{
		all_sh[sh_nb].mb_x = 0;
		all_sh[sh_nb].mb_y += 1;
		ft_sh_in(m, min_box, sh_nb, all_sh);
	}
	return (1);
}

/*
** **************************************************************************
**	----int	ft_f_offset(int p_nb)----
** **************************************************************************
*/

int			ft_p_offset(int p_nb)
{
	if (p_nb != 4)
		return (1);
	else
		return (0);
}

/*
** **************************************************************************
**	----int ft_sh_in(int m, char min_box[m][m])----
**	Function correctly place one shape in min_box
** **************************************************************************
*/

int			ft_sh_in(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	char	sh_letter;
	int		p_nb;

	p_nb = 0;
	ft_mb_chk(m, min_box, sh_nb, all_sh);
	sh_letter = 'A' + sh_nb;
	while (p_nb < 4)
	{
		min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
		[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] = sh_letter;
		p_nb++;
	}
	return (1);
}
