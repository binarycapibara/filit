/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:12:43 by drafe             #+#    #+#             */
/*   Updated: 2019/05/28 19:35:17 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strequ(char const *s1, char const *s2)
{
	size_t		size;

	if ((s1 == NULL) && (s2 == NULL))
		return (1);
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	if ((s1[0] == '\0') && (s2[0] == '\0'))
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	size = ft_strlen(s1);
	return (ft_strnequ(s1, s2, size));
}
