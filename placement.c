/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/22 01:48:34 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_rel_c(t_tet *sh_c, int rel_c[2][4], t_kvars *d, char *seq)
{
	int		m;
	int		n;

	m = 0;
	n = 0;
	while (m != 4)
	{
		rel_c[0][m] = sh_c[seq[d->l] - 65].y[0] - sh_c[seq[d->l] - 65].y[m];
		m++;
	}
	while (n != 4)
	{
		rel_c[1][n] = sh_c[seq[d->l] - 65].x[0] - sh_c[seq[d->l] - 65].x[n];
		n++;
	}
}

void		clear_tetr(t_kvars *d, char letter)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m <= d->size)
	{
		while (n <= d->size)
		{
			if (d->box[m][n] == letter)
				d->box[m][n] = '.';
			n++;
		}
		n = 0;
		m++;
	}
}

int			ft_put(t_tet *sh_c, t_kvars *d, char *seq)
{
	int n;
	int rel_c[2][4];

	n = 0;
	ft_memset(rel_c, 0, sizeof(rel_c));
	ft_rel_c(sh_c, rel_c, d, seq);
	while (n < 4)
	{
		if ((d->n - rel_c[1][n]) < 0 || (d->m - rel_c[0][n]) >= d->size
				|| (d->n - rel_c[1][n]) >= d->size)
		{
			return (0);
		}
		if (d->box[d->m - rel_c[0][n]][d->n - rel_c[1][n]] == '.')
		{
			d->box[d->m - rel_c[0][n]][d->n - rel_c[1][n]] = seq[d->l];
		}
		else
		{
			return (0);
		}
		n++;
	}
	return (1);
}

int			ft_rec(t_tet *sh_c, t_kvars *d, char *seq, int fig)
{
	int m;
	int n;

	m = 0;
	n = 0;
	if (fig >= d->num)
		return (1);
	while (m < d->size)
	{
		n = 0;
		while (n < d->size)
		{
			d->l = fig;
			clear_tetr(d, seq[d->l]);
			d->n = n;
			d->m = m;
			if (ft_put(sh_c, d, seq) && ft_rec(sh_c, d, seq, fig + 1))
				return (1);
			else
				clear_tetr(d, seq[d->l]);
			n++;
		}
		m++;
	}
	return (0);
}

void		worker(t_tet *sh_c, t_kvars *d, char *seq)
{
	int m;
	int n;

	while (!ft_rec(sh_c, d, seq, 0))
		d->size++;
	m = 0;
	n = 0;
	while (m != d->size)
	{
		while (n != d->size)
		{
			ft_putchar(d->box[m][n]);
			n++;
		}
		ft_putchar('\n');
		n = 0;
		m++;
	}
	m = 0;
	while (m <= 25)
	{
		free(d->box[m]);
		m++;
	}
	free(d->box);
}
