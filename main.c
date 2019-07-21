/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 16:06:01 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

//int					ft_find_n(char *s)
//{
//    int				shp;
//    int				p_nb;
//    int				i;
//
//    shp = 0;
//    p_nb = 0;
//    i = 0;
//    while (s[i] != '\0')
//    {
//        if (s[i] == '#')
//            p_nb++;
//        if (p_nb == 4)
//        {
//            shp++;
//            p_nb = 0;
//        }
//        i++;
//    }
//    if (shp > 26)
//    {
//        ft_putstr_fd("error\n", 2);
//        exit(0);
//    }
//    return (shp);
//}


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
	int				tmp;

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
				all_sh[sh_nb].x[p_nb] = all_sh[sh_nb].x[p_nb - 1] + ft_x_c(s, i);
				all_sh[sh_nb].y[p_nb] = all_sh[sh_nb].y[p_nb - 1] + ft_y_c(s, i);
			}
			p_nb++;
		}
		if (s[i] == '\n')
		{
			nl_nb++;
			if ((nl_nb % 5 == 0) && (nl_nb != 0))
			{
                all_sh[sh_nb].litera = 'A' + sh_nb;
				sh_nb++;
				nl_nb = 0;
				p_nb = 0;
			}
		}
		i++;
	}
	tmp = sh_nb;
    all_sh[sh_nb].litera = 'A' + sh_nb;
	return (tmp);
}


int					ft_tetra_read(char *source_f)
{
	static          t_tetris	all_shapes[26];
	t_tetris		*ptr;
	char			*buff;
	int				bytes;
	unsigned int	fd;
	int				*N;
	int				k;

	bytes = 0;
	ptr = all_shapes;
	if (!(fd = open(source_f, O_RDONLY)))
	{
		ft_putstr_fd("read error\n", 2);
		exit(0);
	}
	buff = (char*)ft_strnew(546);
    if ((bytes = read(fd, buff, 545)) < 0)
    {
        ft_putstr_fd("error\n", 2);
        ft_strdel(&buff);
        exit(0);
    }
	buff[bytes] = '\0';
    if ((!ft_valid(buff) || ((close(fd)) < 0)))
    {
        ft_putstr_fd("error\n", 2);
        ft_strdel(&buff);
        exit(0);
    }
	k = ft_save_shape(buff, ptr);
	N = &k;
	ft_algo(N, ptr);
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
