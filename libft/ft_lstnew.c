/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:51:52 by drafe             #+#    #+#             */
/*   Updated: 2019/06/01 17:33:15 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = (void*)malloc(sizeof(content) * content_size)))
		{
			free(tmp->content);
			free(tmp);
			return (0);
		}
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
