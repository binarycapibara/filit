/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:55:05 by drafe             #+#    #+#             */
/*   Updated: 2019/05/30 18:07:18 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if ((!s2 || !s1) || (!s1 && !s2) || (j = 0))
		return ((char*)s1);
	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2);
	i = len_s1 - 1;
	res = NULL;
	if (!(res = (char*)malloc(sizeof(char) * (len_s1 + len_s2))))
		return (0);
	while (len_s1--)
		res[len_s1] = s1[len_s1];
	while (len_s2--)
	{
		if (s2[j] == '\0')
			break ;
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}
