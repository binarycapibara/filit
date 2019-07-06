/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:20:40 by drafe             #+#    #+#             */
/*   Updated: 2019/05/28 19:47:05 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_get_size(int n)
{
	int			tmp;
	int			size;

	size = 1;
	if ((tmp = n) < 0)
	{
		tmp = -tmp;
		size++;
	}
	while ((tmp = (tmp / 10)) > 0)
		size++;
	return (size);
}

static char		*ft_itoa_min(int n, int size)
{
	char		*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (size))))
		return (0);
	n = -214748364;
	ret = ft_itoa(n);
	ret[size - 1] = 56;
	ret[size] = '\0';
	return (ret);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			sign;
	int			size;

	size = ft_itoa_get_size(n);
	if (n == -2147483648)
		return (ft_itoa_min(n, 11));
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n == 0)
		s[0] = '0';
	if ((sign = n) < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[size] = '\0';
	size = size - 1;
	while (n > 0)
	{
		s[size--] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
