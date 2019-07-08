/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 17:33:30 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_tetris
{
	int			x[4];
	int			y[4];
}					t_tetris;

int			ft_box_insert_shape(int m, char min_box[m][m], t_tetris *all_sh);
int			ft_box_size(int n);
int			ft_box_create(int m, t_tetris *all_sh);
int			ft_box(int sh_nb, t_tetris *all_sh);

#endif
