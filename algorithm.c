/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/09 19:19:10 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_get_min_box(int	size)
{	
int 	n;
int		m;	
char	**box;

box = malloc(sizeof(char*) * size);
n = 0;
m = 0;
while (n != size)
    {
        box[n] = malloc(sizeof(char *) * (size - 1));
        n++;
    }
m = 0;
n = 0;
while (m != size)
	{
		while (n != size)
		{
			box[m][n] = '.';
			n++;
		}
		n = 0;
		m++;
	}
return (box);
}

static void    ft_reposition_coord_neg(t_tetris *sh_coord, int *N)
{
    int     sh_nb;
    int     p_nb;
    int     num;

    int     temp;

    sh_nb = 0;
    p_nb = 0;
    num = *N;

   while(sh_nb != (num + 1))
   {
       while (p_nb != 4)
       {
           if (sh_coord[sh_nb].x[p_nb] < 0)
           {
               temp = sh_coord[sh_nb].x[p_nb];
               temp = (temp * (-1));
               p_nb = 0;
               while (p_nb != 4)
               {
                   sh_coord[sh_nb].x[p_nb] = sh_coord[sh_nb].x[p_nb] + temp;
                   p_nb++;
               }
           p_nb = 0;
           }
       p_nb++;
       }
   p_nb = 0;
   sh_nb++;
   }
}

void    ft_algo(int	*N, t_tetris *sh_coord)
{
    int     sh_nb;
    char    sequence[*N];
    t_dimensions dimension;

    dimension.size = 2;
    dimension.N = *N + 1;
    dimension.box = ft_get_min_box(26);
    ft_memset(sequence, 0, sizeof(sequence));
    sh_nb = 0;
    while (sh_nb <= *N)
    {
        sequence[sh_nb] = sh_coord[sh_nb].litera;
        sh_nb++;
    }
    ft_reposition_coord_neg(sh_coord, N);
    worker(sh_coord, &dimension, sequence);
}