/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/06/29 18:09:19 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int					ft_x_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	res = res % 5;
	if ((res < 5) && (res > 1))
		res = res - 5;
	return (res);
}

int					ft_y_c(char *s, int i)
{
	int				res;

	res = 1;
	while (s[i - res] != '#')
		res++;
	if (res < 3)
		res = 0;
	else
		res = 1;
	return (res);
}

int					ft_save_shape(char *s, t_tetris *all_sh)
{
	int				p_nb;
	int				nl_nb;
	int				sh_nb;
	int				i;

	i = 0;
	sh_nb = 0;
	nl_nb = 0;
	p_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (p_nb == 0)
			{
				all_sh[sh_nb].x[p_nb] = 0;
				all_sh[sh_nb].y[p_nb] = 0;
			}
			else
			{
				all_sh[sh_nb].y[p_nb] = all_sh[sh_nb].y[p_nb - 1] + ft_y_c(s, i);
				all_sh[sh_nb].x[p_nb] = all_sh[sh_nb].x[p_nb - 1] + ft_x_c(s, i);
			}
			p_nb++;
		}
		if ((s[i] == '\n') && ((nl_nb++) && ((nl_nb % 5 == 0) && (nl_nb != 0))))
		{
			sh_nb++;
			nl_nb = 0;
			p_nb = 0;
		}
		i++;
	}
	return (0);
}

/*
**	sh_nb = 0;
** 	while (sh_nb < 19)
**	{
**		i = 0;
**		printf("\n***vvv***%d***vvv***", sh_nb);
**		while (i < 4)
**		{
**			printf("\nt[%d].x[%d]=%d  y[%d]=%d", sh_nb,
**			i, all_sh[sh_nb].x[i], i, all_sh[sh_nb].y[i]);
**			i++;
**		}
**		sh_nb++;
**	}
*/

int					ft_tetra_read(char *source_f)
{
	static t_tetris	all_shapes[26];
	t_tetris		*ptr;
	char			*tmp;
	int				bytes;
	unsigned int	fd;

	bytes = 0;
	ptr = all_shapes;
	if (!(fd = open(source_f, O_RDONLY)))
	{
		ft_putstr_fd("read error\n", 2);
		exit(0);
	}
	tmp = (char*)ft_strnew(521);
	bytes = read(fd, tmp, 520);
	if (bytes < 0)
		return (-1);
	tmp[bytes] = '\0';

	ft_save_shape(tmp, ptr);
	if ((close(fd)) < 0)
	{
		ft_putstr_fd("close error\n", 2);
		exit(0);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		exit(1);
	}
	ft_tetra_read(argv[1]);
}
/*
**  1 line with 8 chars with Line Feed
*/
