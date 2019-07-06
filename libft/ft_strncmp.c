/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:21:33 by drafe             #+#    #+#             */
/*   Updated: 2019/05/29 20:02:03 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i <= n)
	{
		if (s1[i] != s2[i])
			break ;
		if ((s1[i] == '\0') || (s2[i] == '\0'))
			break ;
		i++;
	}
	if (i < n)
		return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	else
		return (0);
}
