/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:00:54 by drafe             #+#    #+#             */
/*   Updated: 2019/06/02 19:04:10 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	void	*data;

	tmp = *alst;
	data = tmp->content;
	*alst = tmp->next;
	if (alst != NULL)
	{
		if (del != NULL)
			del(tmp->content, tmp->content_size);
		free(tmp);
		alst = NULL;
	}
}
