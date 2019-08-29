/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:09:37 by drafe             #+#    #+#             */
/*   Updated: 2019/05/29 16:17:16 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_s(const char *haystack, const char *needle,\
					size_t len, int sw)
{
	size_t		i;
	size_t		eq;

	i = 0;
	eq = 0;
	while ((haystack[i] != '\0') && (i < len))
	{
		if (eq == ft_strlen(needle))
			break ;
		if (haystack[i] == needle[eq])
			eq++;
		else if (haystack[i] == needle[eq = 0])
			i--;
		else
			eq = 0;
		i++;
	}
	if (sw && (eq == ft_strlen(needle)))
		return (eq);
	else if (sw)
		return (0);
	return (i);
}

char			*ft_strnstr(const char *haystack,\
							const char *needle, size_t len)
{
	size_t		i;
	size_t		eq;

	i = 0;
	eq = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	if (len <= 0 || (ft_strlen(haystack) < ft_strlen(needle)))
		return (0);
	while ((*haystack != '\0') && len)
	{
		eq = ft_s((char*)haystack, needle, len, 1);
		if (eq != 0)
		{
			i = ft_s(haystack, needle, len, 0);
			return ((char*)(haystack += (i - eq)));
		}
		len--;
		haystack++;
		i++;
	}
	return (0);
}
