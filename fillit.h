/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/10 18:38:55 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_coords
{
	int			x[4];
	int			y[4];
	int			mb_x;
	int			mb_y;
}				t_coords;

int				ft_box_in(int m, char min_box[m][m], t_coords *all_sh);
int				ft_box_size(int n);
int				ft_box_create(int m, t_coords *all_sh);
int				ft_box(int sh_nb, t_coords *all_sh);
int				ft_sh_in(int m, char min_box[m][m],int sh_nb, t_coords *all_sh);
int				ft_p_offset(int p_nb);
int				ft_x_c(char *s, int i);
int				ft_y_c(char *s, int i);
int				ft_save_shape(char *s, t_coords *all_sh);
int				ft_tetra_read(char *source_f);
void			ft_lstbzero(t_coords *all_sh);

#endif
