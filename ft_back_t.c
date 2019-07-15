/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/07/15 20:45:32 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	(1)void ft_swap_sh(int sh_nb1, int sh_nb2, t_crds *all_sh)
**	Function swap elements of t_crds array
** **************************************************************************
*/

void			ft_swap_sh(int sh_nb1, int sh_nb2, t_crds *all_sh)
{
	t_crds		ptr;

	ptr = all_sh[sh_nb1];
	all_sh[sh_nb1] = all_sh[sh_nb2];
	all_sh[sh_nb2] = ptr;
}

/*
** **************************************************************************
**	(2)int	ft_back_t(int m, int pos, int size, t_crds *all_sh)
**	Function to backtrace
** **************************************************************************
*/

int				ft_back_t(int m, int pos, int size, t_crds *all_sh)
{
	int			i;

	i = 0;
	if (pos == size)//очередная перестановка готова
		return (1);
	while (i < size)//переберем
	{
		if (!all_sh[i].used)//если еще не ставили
		{
			ft_swap_sh(pos, i , all_sh); //поставим
			all_sh[i].used = 1;
			ft_back_t(m, pos + 1, size, all_sh);
			//ft_swap_sh(pos, 0, all_sh);
		}
		i++;
	}
	i = 0;
	while(i < size)
	{
		printf("%d%c ", i, all_sh[i].sh_let);
		i++;
	}
	return (0);
}
