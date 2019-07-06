/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:38:53 by drafe             #+#    #+#             */
/*   Updated: 2019/05/19 19:22:23 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (!(tmp = malloc(size)))
		return (0);
	while (i < size)
	{
		tmp[i] = (char)'\0';
		i++;
	}
	ft_bzero(tmp, size);
	return (tmp);
}
