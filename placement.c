/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/09 19:19:10 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_box_print(char **box, int size)
{
    int m;
    int n;

    m = 0;
    n = 0;
    while (m != size)
    {
        while (n != size)
        {
            printf("%c", box[m][n]);
            n++;
        }
        n = 0;
        printf("\n");
        m++;
    }
}

static void ft_relative_coords(t_tetris *sh_coord, int relative_coords[2][4], t_dimensions *d, int     *sequence)
{
    int     m;
    int     n;

    m = 0;
    n = 0;
        while (m != 4)
        {
            relative_coords[0][m] = sh_coord[sequence[d->l]].y[0] - sh_coord[sequence[d->l]].y[m];
            m++;
        }
        while (n != 4)
        {
            relative_coords[1][n] = sh_coord[sequence[d->l]].x[0] - sh_coord[sequence[d->l]].x[n];
            n++;
        }

}

int     ft_attempt_write(char **box, t_tetris *sh_coord, t_dimensions *d, int    *sequence)
{
    int m;
    int n;
    int counter;
    char litera;
    char       **box_tmp;
    int relative_coords[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    m = 0;
    n = 0;
    box_tmp = ft_get_min_box(d->size);
    ft_memset(relative_coords, 0, sizeof(relative_coords));

    ft_relative_coords(sh_coord, relative_coords, d, sequence);


    printf("call of relative coords again in main body function ft_attempt_write\n");
    while (n != 4)
    {
        printf("%i\n", relative_coords[0][n]);
        n++;
    }
    printf("next\n");
    n = 0;
    while (n != 4)
    {
        printf("%i\n", relative_coords[1][n]);
        n++;
    }
    printf("next\n");

    n = 0;
    printf("printing array without first figure\n");
    ft_box_print(box, d->size);
    while (n < 4)
    {
        if ((d->n - relative_coords[0][n]) < 0 || (d->m - relative_coords[0][n]) >= d->size
            || (d->n - relative_coords[1][n]) >= d->size)
        {
            return (0);
        }
        if (box[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]] == '.')
        {
            box_tmp[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]] = ('A' + d->l);
        }
        else
        {
            ft_memset(box_tmp, ',', sizeof(box_tmp));
            return (0);
        }
        n++;
    }
    printf("printing array with first figure\n");
    ft_box_print(box, d->size);
    printf("\n");
    ft_box_print(box_tmp, d->size);
    m = 0;
    n = 0;
    while (m != d->size)
    {
        while (n != 4)
        {
            box[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]] = box_tmp[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]];
            n++;
        }
        n = 0;
        m++;
    }
    printf("\n");
    ft_box_print(box, d->size);
    return (1);
}

int     ft_placement(char **box, t_tetris *sh_coord, t_dimensions *d, int *sequence)
{
    int m;
    int n;
    int l;
    int figure_count;
    int sh_nb;
    int res;
    char litera;

    m = 0;
    n = 0;
    l = 0;
    res = 0;
    figure_count = 0;
    //test 1
    printf("print empty box\n");
    ft_box_print(box, d->size);
    while (l != (d->N + 1))
    {
        while (m < d->size)
        {
            n = 0;
            while (n < d->size)
            {
                if (box[m][n] == '.')
                {
                    d->litera = 'A' + l;
                    d->n = n;
                    d->m = m;
                    d->l = l;
                    res = ft_attempt_write(box, sh_coord, d, sequence);
                    printf("%i\n\n", res);
                    if (res == 1)
                    {
                        m = d->size;
                        break;
                    }
                }
                n++;
            }
            m++;
            if (n == d->size && m == d->size && l <= d->N && res == 0)
            {
                return (0);
            }
        }
        n = 0;
        m = 0;
        l++;
    }
    return (1);
}

//int         worker(char **box, t_tetris *sh_coord, t_dimensions *d, int *sequence)
//{
//    int     i;
//    int     y;
//    int     x;
//
//    i = 0;
//    y = 0;
//
//    while (y < (d->size - 1))
//    {
//        x = 0;
//        while ((x + 1) < d->size)
//        {
//            if (ft_placement(box, sh_coord, d, sequence) && worker
//
//
//
//        }
//
//
//
//
//
//
//
//    }
//
//
//
//
//}