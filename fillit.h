/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 16:06:39 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_tetris
{
	int			x[4];
	int			y[4];
	char        litera;
}					t_tetris;

typedef struct      s_dimensions
{
    int         size;
    int         N;
    int         m;
    int         n;
    int         l;
    char        **box;
    char        litera;
}                   t_dimensions;

typedef struct      s_1dot
{
    int         x;
    int         y;
}                   t_1dot;

void            ft_algo(int	*N, t_tetris *sh_coord);
int             ft_placement(t_tetris *sh_coord, t_dimensions *dimension, char *sequence, int one_more_figure);
void            ft_box_print(t_dimensions *d, int size);
int             ft_attempt_write(t_tetris *sh_coord, t_dimensions *d, char    *sequence);
char	        **ft_get_min_box(int	size);
void             worker(t_tetris *sh_coord, t_dimensions *d, char *sequence);

#endif
