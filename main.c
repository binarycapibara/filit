/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/20 22:35:20 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_find_n(char *s)
{
	int				shp;
	int				p_nb;
	int				i;

	shp = 0;
	p_nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			p_nb++;
		if (p_nb == 4)
		{
			shp++;
			p_nb = 0;
		}
		i++;	
	}
	if (shp > 26)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
	return (shp);
}

void				ft_lstbzero(t_crds *all_sh, int n_sh)
{
	int				sh_nb;
	int				p_nb;

	sh_nb = 0;
	p_nb = 0;
	while (sh_nb < n_sh)
	{
		all_sh[sh_nb].mb_x = 0;
		all_sh[sh_nb].mb_y = 0;
		all_sh[sh_nb].sh_let = 'A' + sh_nb;
		p_nb = 0;
		while (p_nb < 4)
		{
			all_sh[sh_nb].x[p_nb] = 0;
			all_sh[sh_nb].y[p_nb] = 0;
			p_nb++;
		}
		sh_nb++;
	}
}

int					ft_tetra_read(char *source_f)
{
	char			*buff;
	int				bytes;
	int				fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("error\n", 2);
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
	if ((!ft_valid(buff, ft_find_n(buff))) || ((close(fd)) < 0))
	{
		ft_putstr_fd("error\n", 2);
		ft_strdel(&buff);
		exit(0);
	}
	ft_strdel(&buff);
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
