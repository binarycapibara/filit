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

int					ft_tetra_read(char *source_f)
{
	static          t_tetris	all_shapes[26];
	t_tetris		*ptr;
	char			*buff;
	int				bytes;
	unsigned int	fd;
	int				*N;
	int				k;

	ptr = all_shapes;
	if (!(fd = open(source_f, O_RDONLY)))
	{
		ft_putstr("error\n");
		exit(1);
	}
	buff = (char*)ft_strnew(546);
    if ((bytes = read(fd, buff, 545)) <= 0)
    {
        ft_putstr("error\n");
        ft_strdel(&buff);
        exit(1);
    }
	buff[bytes] = '\0';
    if ((!ft_valid(buff) || ((close(fd)) < 0)))
    {
        ft_putstr("error\n");
        ft_strdel(&buff);
        exit(1);
    }
	k = ft_save_shape(buff, ptr);
	N = &k;
	ft_algo(N, ptr);
	return (fd);
}

int					main(int argc, char **argv)
{
    int             fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	fd = ft_tetra_read(argv[1]);
    close(fd);
    exit(0);
}
