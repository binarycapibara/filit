/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/07 21:24:41 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static		ft_box_calc (int	**N, char		***box)
{
	int		res;
	
	res = *N;
	res = ft_sqrt(res * 4);
	*N = res;
	return ;
}










ft_core_algo(int	*N, char	**sh_coord)
{
	char		**box[0][0];

	ft_box_calc(&N, &box);
	return ;
}