/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:09:14 by drafe             #+#    #+#             */
/*   Updated: 2019/07/08 16:06:01 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_symb_chk(char *s)
{
    int		i;
    int		p_nb;
    int		tetr_line;
    int		sh_n;


    i = 0;
    p_nb = 0;
    tetr_line = 0;
    sh_n = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
            p_nb++;
        if(s[i] == '\n' && s[i + 5] == '\n')
            tetr_line++;
        if (tetr_line == 4 && p_nb == 4)
            sh_n++;
        if ((p_nb % 4 != 0) && (tetr_line % 4 != 0) && s[i] == '\0')
            return (0);
        i++;
    }
    return (1);
}

int			ft_nl_chk(char *s)
{
    int		i;
    int     m;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '.' || s[i] == '#' || s[i] == '\n')
            i++;
        else
            return (0);
    }
    i = 1;
    m = 0;
    while (s[i] != '\0')
    {
        if ((i - m) % 20 == 0)
        {

            if (s[i - m] == '\n' || s[i - m] == '\0')
                m++;
            else
                return (0);
        }
        i++;
    }
    return (1);

}
int			ft_shp_chk(char *s)
{
    int		i;
    int		p_nb;

    i = 0;
    p_nb = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
            p_nb++;
        if ((s[i] == '\n') && ((s[i + 1] == '\0') || (s[i + 1] == '\n')))
        {
            if (p_nb != 4)
                return (0);
            p_nb = 0;
        }
        i++;
    }
    return (1);
}

int			ft_sh_size(char *s)
{
    int		i;
    int		p_nb;
    int		sh_touch;
    int		touch_sum;

    i = 0;
    p_nb = 0;
    touch_sum = 0;
    sh_touch = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '#')
        {
            if (s[i + 1] == '#')
                sh_touch++;
            if(s[i + 5] == '#')
                sh_touch++;
            if (s[i - 1] == '#')
                sh_touch++;
            if(s[i - 5] == '#')
                sh_touch++;
            if ((sh_touch == 0) || (sh_touch > 4))
                return (0);
            p_nb++;
            touch_sum += sh_touch;
            sh_touch = 0;
        }
        if (p_nb == 4)
        {
            if ((touch_sum > 9) || (touch_sum < 5))
                return (0);
            touch_sum = 0;
            p_nb = 0;
        }
        i++;
    }
    return (1);
}

int			ft_valid(char *s)
{
    if (!ft_nl_chk(s))
        return (0);
    if (!ft_symb_chk(s))
        return (0);
    if (!ft_shp_chk(s))
        return (0);
    if (!ft_sh_size(s))
        return (0);
    return (1);
}
