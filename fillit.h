/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:07:55 by drafe             #+#    #+#             */
/*   Updated: 2019/07/25 16:55:47 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_tet
{
	int			x[4];
	int			y[4];
	char		litera;
}					t_tet;

typedef struct		s_kvars
{
	int			size;
	int			num;
	int			m;
	int			n;
	int			l;
	char		**box;
}					t_kvars;

typedef struct		s_ft_tetra_read_holder
{
	char			*buff;
	int				bytes;
	int				fd;
}					t_ft_tetra_read_holder;

typedef struct		s_ft_symb_check_holder
{
	int		i;
	int		p_nb;
	int		tetr_l;
	int		n_of_ns;
}					t_ft_symb_check_holder;

typedef struct		s_ft_save_shape_holder
{
	int				p_n;
	int				nl_nb;
	int				sh_nb;
	int				i;
}					t_ft_save_shape_holder;

typedef struct		s_ft_reposition_coord_neg
{
	int				sh_nb;
	int				p_nb;
	int				num;
	int				te;
}					t_ft_reposition_coord_neg;

typedef struct		s_ft_valid_touch_holder
{
	int				i;
	int				p_nb;
	int				sh_touch;
	int				touch_sum;
}					t_ft_valid_touch_holder;

typedef struct		s_ft_get_min_box_holder
{
	int				n;
	int				m;
	char			**box;
}					t_ft_get_min_box_holder;

int					ft_tetra_read(char *source_f);
int					ft_valid(char *s);
int					ft_shp_chk(char *s);
int					ft_nl_chk(char *s);
int					ft_symb_chk(char *s);
int					ft_sh_size(char *s);
int					ft_save_shape(char *s, t_tet *all_sh);
void				ft_algo(int	num, t_tet *sh_c);
char				**ft_get_min_box(int	size);
void				worker(t_tet *sh_c, t_kvars *d, char *seq);
int					ft_rec(t_tet *sh_c, t_kvars *d, char *seq, int fig);
int					ft_put(t_tet *sh_c, t_kvars *d, char *seq);

#endif
