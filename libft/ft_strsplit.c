/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:53:53 by drafe             #+#    #+#             */
/*   Updated: 2019/05/31 19:39:06 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split_free(char **res, size_t n)
{
	while (n--)
		free(res[n]);
	free(res);
	return (0);
}

static char		**ft_strsplit_res_out(char **res, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		n;
	size_t		len;

	i = 0;
	j = 0;
	len = 0;
	n = 0;
	while (i < ft_strlen(s) + 1)
	{
		if ((s[i] != c) && (s[i] != '\0'))
			len++;
		if (((len != 0) && ((s[i] == c) || (s[i] == '\0'))) || (j = 0))
		{
			if (!(res[n] = (char*)malloc(sizeof(char) * (len + 1))))
				return (ft_split_free(res, n));
			res[n][len] = '\0';
			while (len != 0)
				res[n][j++] = s[(i - 1) - (--len)];
			n++;
		}
		i++;
	}
	return (res);
}

static size_t	ft_strsplit_find_n(char const *s, char c)
{
	size_t		i;
	size_t		n;
	size_t		len;

	i = 0;
	len = 0;
	n = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && s[i] != '\0')
			len++;
		if ((len != 0) && ((s[i] == c) || (s[i] == '\0')))
		{
			while (len != 0)
				--len;
			n++;
		}
		i++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		n;

	if (!s)
		return (0);
	n = ft_strsplit_find_n(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (n + 1))))
		return (0);
	res[n] = (char*)'\0';
	res = ft_strsplit_res_out(res, s, c);
	return (res);
}
