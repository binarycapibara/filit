/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/12 18:02:38 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	-void	ft_p_a(int m, char min_box[m][m])-
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
**	-int	ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)-
**	Function to check correct place of shape in min_box
** **************************************************************************
*/

int		ft_mb_chk(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	int		p_nb;

	p_nb = 0;
	while (p_nb < 4)
	{
		if((all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb] >= m) || \
		(all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb] >= m))
			break ;
		if (min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
		[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] != '.')
			break ;
		p_nb++;
	}
	return (ft_p_offset(m , p_nb, sh_nb, all_sh));
}
/*
** **************************************************************************
**	-int	ft_p_move(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)-
**	Function to move shape through min_box
**	check all shape points fit in or not
**	
** **************************************************************************
*/

int			ft_p_move(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	int		chk;

	chk = 0;
	printf("sh_nb=%d chk=%d all_sh[p_nb].mb_x=%d\n", sh_nb, chk, all_sh[sh_nb].mb_x);
	while (!chk && (all_sh[sh_nb].mb_y < m))
	{
		chk = ft_mb_chk(m, min_box, sh_nb, all_sh);
	}
	if (chk)
		return (1);
	return (0);
	/*ft_p_move(m, min_box, sh_nb, all_sh);
		return (0); */
}

/*
** **************************************************************************
**	----int	ft_f_offset(int p_nb)----
**	Function move shape to next + 1 point
** **************************************************************************
*/

int			ft_p_offset(int m, int p_nb, int sh_nb, t_coords *all_sh)
{
	if (p_nb != 4)
	{
		if	(all_sh[sh_nb].mb_x >= m)
		{
			all_sh[sh_nb].mb_x = 0;
			all_sh[sh_nb].mb_y += 1;
		}
		else
			all_sh[sh_nb].mb_x += 1;
		return (0);
	}
	else
		return (1);
}

/*
** **************************************************************************
**	----int ft_sh_in(int m, char min_box[m][m])----
**	Function place one shape in min_box if ft_p_move == 1
** **************************************************************************
*/

int			ft_sh_in(int m, char min_box[m][m], int sh_nb, t_coords *all_sh)
{
	char	sh_letter;
	int		p_nb;

	p_nb = 0;
	if (ft_p_move(m, min_box, sh_nb, all_sh))
	{
		sh_letter = 'A' + sh_nb;
		while (p_nb < 4)
		{
			min_box[all_sh[sh_nb].mb_y + all_sh[sh_nb].y[p_nb]]\
			[all_sh[sh_nb].mb_x + all_sh[sh_nb].x[p_nb]] = sh_letter;
			p_nb++;
		}
		return (1);
	}
	else
		return (0);
	
	



	
	ft_mb_chk(m, min_box, sh_nb, all_sh);
	//ft_p_a(m, min_box);
}
