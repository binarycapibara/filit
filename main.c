/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/24 20:34:58 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetra_read(char *source_f)
{
	static	t_tet			all_shapes[26];
	t_ft_tetra_read_holder	var;

	var.fd = open(source_f, O_RDONLY);
	var.buff = (char*)ft_strnew(546);
	if ((var.bytes = read(var.fd, var.buff, 546)) <= 0 || (var.bytes >= 546))
	{
		ft_strdel(&var.buff);
		ft_putstr("error\n");
		exit(1);
	}
	var.buff[var.bytes] = '\0';
	if (!ft_valid(var.buff))
	{
		ft_strdel(&var.buff);
		ft_putstr("error\n");
		exit(1);
	}
	ft_algo(ft_save_shape(var.buff, all_shapes), all_shapes);
	return (var.fd);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	fd = ft_tetra_read(argv[1]);
	close(fd);
	exit(0);
}
