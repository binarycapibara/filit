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

static int		ft_box_calc(int	**N)  //, char		**box)
{
	int		res;
	int     tmp;
	tmp = **N;
	tmp = tmp + 1;
	res = 0;

	(tmp == 1) ? res = 3 : 0;
	(tmp == 2) ? res = 4 : 0;
	(tmp == 3) ? res = 4 : 0;
	(tmp == 4) ? res = 4 : 0;
	(tmp == 5) ? res = 5 : 0;
	(tmp == 6) ? res = 5 : 0;
	(tmp == 7) ? res = 6 : 0;
	(tmp == 8) ? res = 6 : 0;
	(tmp == 9) ? res = 6 : 0;
	(tmp == 10) ? res = 7 : 0;
	(tmp == 11) ? res = 7 : 0;
	(tmp == 12) ? res = 7 : 0;
	(tmp == 13) ? res = 8 : 0;
	(tmp == 14) ? res = 8 : 0;
	(tmp == 15) ? res = 8 : 0;
	(tmp == 16) ? res = 8 : 0;
	(tmp == 17) ? res = 9 : 0;
	(tmp == 18) ? res = 9 : 0;
	(tmp == 19) ? res = 9 : 0;
	(tmp == 20) ? res = 9 : 0;
	(tmp == 21) ? res = 10 : 0;
	(tmp == 22) ? res = 10 : 0;
	(tmp == 23) ? res = 10 : 0;
	(tmp == 24) ? res = 10 : 0;
	(tmp == 25) ? res = 10 : 0;
	(tmp == 26) ? res = 11 : 0;
	return (res);
}

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

void ft_algo(int	*N, t_tetris *sh_coord) {
    int sh_nb;
    int i;
    int k;
    int size;
    int *size_ptr;
    int m;
    int n;
    int result_figure_placement;
    char **box;
    char *box_tmp;
    int sequence[*N];
    t_1dot position;
    t_dimensions dimension;

    result_figure_placement = 1;
    ft_memset(sequence, 0, sizeof(sequence));
    sh_nb = 0;
    while (sh_nb <= *N)
    {
        sequence[sh_nb] = sh_nb;
        sh_nb++;
    }
    sh_nb = 0;
    k = *N;
    box = NULL;
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
    m = 0;
    ft_reposition_coord_neg(sh_coord, N);
    sh_nb = 0;
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
    printf("\n-------------------------------------------");
    printf("\n-------------------------------------------\n");
    size = ft_box_calc(&N);
    printf("number of elements - [%d]\n", *N);
    printf("array size - [%d] х [%d]\n", size, size);
    m = 0;
    n = 0;
    box = ft_get_min_box(size);
    printf("empty box test that it actually filled with dots and exists\n");
    ft_box_print(box, size);
    dimension.size = size;
    dimension.N = *N;

    while (1)
    {
        result_figure_placement = ft_placement(box, sh_coord, &dimension, sequence);
        if (result_figure_placement == 0)
        {
            printf("not all figures fit");
            break;
        }
        if (result_figure_placement == 1)
        {
            printf("success");
            break;
        }
    }
}