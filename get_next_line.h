/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_chk.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 21:16:03 by drafe             #+#    #+#             */
/*   Updated: 2019/06/10 16:15:17 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_tetris
{
	int			x[4];
	int			y[4];
}					t_tetris;

int			get_next_line(const int fd, char **line);
#endif
