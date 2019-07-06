/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:43:23 by drafe             #+#    #+#             */
/*   Updated: 2019/05/28 19:33:12 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	dst_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	dst_len = ft_strlen(s);
	if ((dst_len - start < len) && (len > (size_t)-1))
		len = dst_len - start;
	if ((dst_len < start) || (!(res = (char*)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	while (i < len)
	{
		if (s[start] == '\0')
			break ;
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
