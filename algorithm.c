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
    int     m;
    int     n;
    int     temp;

    sh_nb = 0;
    p_nb = 0;
    num = *N;
    m = 0;
    n = 0;

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
    int     i;
    int     k;
    int     size;
    char    sequence[*N];
    t_dimensions dimension;

    ft_memset(sequence, 0, sizeof(sequence));
    sh_nb = 0;
    while (sh_nb <= *N)
    {
        sequence[sh_nb] = sh_coord[sh_nb].litera;
        sh_nb++;
    }
    sh_nb = 0;
    printf("\ncheck that sequence contains correct letters initially\n");
    while (sh_nb <= *N)
    {
        printf("%c\n", sequence[sh_nb]);
        sh_nb++;
    }
    sh_nb = 0;

//    sequence [6] = 'A';
//    sequence [5] = 'B';
//    sequence [4] = 'C';
//    sequence [3] = 'D';
//    sequence [2] = 'E';
//    sequence [1] = 'F';
//    sequence [0] = 'G';

    k = *N;
    printf("\nprint number of elements\n");
    printf("%d\n", k);
    while (sh_nb <= *N) {
        i = 0;
        printf("\n***vvv***%d***vvv***", sh_nb);
        while (i < 4) {
            printf("\nt[%d].x[%d]=%d  y[%d]=%d", sh_nb, i, sh_coord[sh_nb].x[i], i, sh_coord[sh_nb].y[i]);
            i++;
        }
        sh_nb++;
    }
    printf("\n-------------------------------------------");
    ft_reposition_coord_neg(sh_coord, N);
    sh_nb = 0;
    while (sh_nb <= *N) {
        i = 0;
        printf("\n***vvv***%d***vvv***", sh_nb);
        while (i < 4) {
            printf("\nlitera[%c]t[%d].x[%d]=%d  y[%d]=%d", sh_coord[sh_nb].litera, sh_nb, i, sh_coord[sh_nb].x[i], i, sh_coord[sh_nb].y[i]);
            i++;
        }
        sh_nb++;
    }

    printf("\n-------------------------------------------");
    printf("\n-------------------------------------------");
    printf("\n-------------------------------------------\n");
    size = 2;
    printf("number of elements - [%d]\n", *N);
    printf("array size - [%d] х [%d]\n", size, size);
    dimension.size = size;
    dimension.N = *N + 1;
    dimension.box = ft_get_min_box(26);
    worker(sh_coord, &dimension, sequence);
}