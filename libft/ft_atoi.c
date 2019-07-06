/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:09:12 by drafe             #+#    #+#             */
/*   Updated: 2019/05/31 19:20:34 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_spaces(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'		\
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_atoi_spaces(*str))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = (res * 10) + (long)(*str - '0');
		str++;
	}
	return ((int)(res * sign));
}
