/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/20 18:24:04 by drafe            ###   ########.fr       */
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
}				t_crds;

int				ft_p_offset(int m, int p_nb, int sh_nb, t_crds *all_sh);
int				ft_sh_mv(int m, char **min_box, int sh_nb, t_crds *all_sh);
int				ft_plc_sh(int m, char **min_box, int sh_nb, t_crds *all_sh);
void			ft_rm_sh(char **min_box, int m, int sh_nb, t_crds *all_sh);
void			ft_p_a(int m, char **min_box);
int				ft_box_size(int n);
int				ft_tile(char **min_box, int n, t_crds *all_sh, int pos);
char			**ft_box_create(int m);
int				ft_box(int sh_nb, t_crds *all_sh);
int				ft_x_c(char *s, int i);
int				ft_y_c(char *s, int i);
int				ft_save_shape(char *s, t_crds *all_sh);
int				ft_find_n(char *s);
void			ft_lstbzero(t_crds *all_sh, int n_sh);
int				ft_tetra_read(char *source_f);
int				ft_symb_chk(char *s);
int				ft_nl_chk(char *s);
int				ft_shp_chk(char *s);
int				ft_valid(char *s, int n_sh);

#endif
