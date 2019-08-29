/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:56:58 by drafe             #+#    #+#             */
/*   Updated: 2019/05/30 18:52:34 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*tmp_ptr;
	size_t	st;
	size_t	en;
	size_t	i;

	i = 0;
	if (!s || (st = 0))
		return (0);
	en = ft_strlen(s);
	while (((s[st] == ' ') || (s[st] == '\t')) || (s[st] == '\n'))
		st++;
	while (((s[en - 1] == ' ') || (s[en - 1] == '\t')) || (s[en - 1] == '\n'))
		en--;
	if ((int)(i = en - st) < 0)
		i = 0;
	if (!(tmp_ptr = ((char*)malloc((i + 1) * sizeof(*s)))))
		return (0);
	i = 0;
	while (st < en)
		tmp_ptr[i++] = s[st++];
	tmp_ptr[i] = '\0';
	return (tmp_ptr);
}
