/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:05:21 by drafe             #+#    #+#             */
/*   Updated: 2019/05/28 20:05:22 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_cast;
	unsigned char	*src_cast;
	size_t			i;

	i = 0;
	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		if (src_cast[i] == (unsigned char)c)
			return (dst += (i + 1));
		i++;
	}
	return (0);
}
