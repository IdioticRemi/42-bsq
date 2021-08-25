/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:47:07 by kbarbry           #+#    #+#             */
/*   Updated: 2021/08/25 00:22:48 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

long	calc_val(t_bsq *bsq, long x, long y)
{
	long	a;
	long	b;
	long	c;
	long	d;

	a = 0;
	if (x && y)
		a = bsq->grid[x - 1][y - 1];
	b = 0;
	if (y)
		b = bsq->grid[x + bsq->size][y - 1];
	c = 0;
	if (x)
		c = bsq->grid[x - 1][y + bsq->size];
	d = bsq->grid[x + bsq->size][y + bsq->size];
	return (d - c - b + a);
}

void	run_algo(t_bsq *bsq)
{
	long	x;
	long	y;

	bsq->size = 0;
	y = 0;
	while (y < bsq->size_y - bsq->size)
	{
		x = 0;
		while (x < bsq->size_x - bsq->size && y < bsq->size_y - bsq->size)
		{
			if (calc_val(bsq, x, y) > 0)
				x++;
			else
			{
				bsq->size++;
				bsq->sqr_x = x;
				bsq->sqr_y = y;
			}
		}
		y++;
	}
}
