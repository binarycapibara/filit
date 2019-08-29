/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:58:28 by drafe             #+#    #+#             */
/*   Updated: 2019/05/30 18:56:02 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmp;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	d_len = 0;
	tmp = dst;
	while (d_len < size)
	{
		if (!*tmp)
			break ;
		tmp++;
		d_len++;
	}
	if (d_len == size)
		return (size + s_len);
	if (s_len < size - d_len)
		ft_copy(dst + d_len, src, s_len + 1);
	else
	{
		ft_copy(dst + d_len, src, (size - d_len - 1));
		dst[size - 1] = '\0';
	}
	return (s_len + d_len);
}
