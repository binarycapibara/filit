/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:12:54 by drafe             #+#    #+#             */
/*   Updated: 2019/06/02 18:55:13 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*ret;

	start = NULL;
	if ((f != NULL) || (lst != NULL))
		while (lst != NULL)
		{
			if (start == NULL)
			{
				if (!(start = ft_lstnew(f(lst)->content, f(lst)->content_size)))
					return (NULL);
				ret = start;
			}
			else
			{
				if (!(ret->next = ft_lstnew(f(lst)->content,\
											f(lst)->content_size)))
					return (NULL);
				ret = ret->next;
			}
			lst = lst->next;
		}
	return (start);
}
