/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/15 21:07:30 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_crds
{
	char		sh_let;
	int			x[4];
	int			y[4];
	int			mb_x;
	int			mb_y;
	int			used;
}				t_crds;

void			ft_p_a(int m, char min_box[m][m]);
int				ft_box_size(int n);
int				ft_tile(int m, char min_box[m][m], int size, t_crds *all_sh);
int				ft_box_create(int sh_nb, int m, t_crds *all_sh);
int				ft_box(int sh_nb, t_crds *all_sh);
int				ft_plc_sh(int m, char min_box[m][m], int sh_nb, t_crds *all_sh);
int				ft_p_offset(int m, int p_nb, int sh_nb, t_crds *all_sh);
int				ft_x_c(char *s, int i);
int				ft_y_c(char *s, int i);
int				ft_save_shape(char *s, t_crds *all_sh);
int				ft_tetra_read(char *source_f);
void			ft_lstbzero(t_crds *all_sh);
int				ft_sh_mv(int m, char min_box[m][m], int sh_nb, t_crds *all_sh);
int				ft_back_t(int pos, int size, t_crds *all_sh);
void			ft_swap_sh(int sh_nb1, int sh_nb2, t_crds *all_sh);
int				ft_find_empt(int m, char min_box[m][m], int sh_nb, t_crds *all_sh);

#endif
