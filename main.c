/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/15 18:30:56 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** **************************************************************************
**	(1)void	ft_lstbzero(t_crds *all_sh)
**	Function initiallize every member in array of structures with 0
** **************************************************************************
*/

void				ft_lstbzero(t_crds *all_sh)
{
	int				sh_nb;
	int				p_nb;

	sh_nb = 0;
	p_nb = 0;
	while (sh_nb < 26)
	{
		all_sh[sh_nb].mb_x = 0;
		all_sh[sh_nb].mb_y = 0;
		all_sh[sh_nb].used = 0;
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

/*
** **************************************************************************
**	(2)int	ft_tetra_read(char *source_f)
**	Function read 546 bytes from input_file to string *buff
**  and send *buff with pointer to empty array of structures
** **************************************************************************
*/

int					ft_tetra_read(char *source_f)
{
	static t_crds	all_shapes[26];
	t_crds			*ptr;
	char			*buff;
	int				bytes;
	unsigned int	fd;

	ptr = all_shapes;
	ft_lstbzero(ptr);
	if (!(fd = open(source_f, O_RDONLY)))
	{
		ft_putstr_fd("read error\n", 2);
		exit(0);
	}
	buff = (char*)ft_strnew(546);
	bytes = read(fd, buff, 545);
	if (bytes < 0)
		return (-1);
	buff[bytes] = '\0';
	ft_box(ft_save_shape(buff, ptr), ptr);
	if ((close(fd)) < 0)
	{
		ft_putstr_fd("close error\n", 2);
		exit(0);
	}
	return (0);
}

/*
** **************************************************************************
**	(3)int	main(int argc, char **argv)
** **************************************************************************
*/

int					main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		exit(1);
	}
	ft_tetra_read(argv[1]);
}
