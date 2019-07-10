/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/10 15:22:48 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_coords
{
	int				x[4];
	int				y[4];
}					t_coords;

int					ft_box_in(int m, char min_box[m][m], t_coords *all_sh);
int					ft_box_size(int n);
int					ft_box_create(int m, t_coords *all_sh);
int					ft_box(int sh_nb, t_coords *all_sh);
int					ft_one_sh(int m, char min_box[m][m], int i, t_coords *all_sh);
int					ft_f_offset(int p_nb);

#endif
