/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:38:18 by kbarbry           #+#    #+#             */
/*   Updated: 2021/08/25 05:14:09 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_grid(t_bsq *bsq)
{
	t_uint	x;

	x = 0;
	while (x < bsq->size_x)
		free(bsq->grid[x++]);
	free(bsq->grid);
}

t_bool	allocgrid(t_bsq *bsq)
{
	t_uint	i;
	t_uint	j;

	bsq->grid = malloc(sizeof(t_uint *) * bsq->size_x);
	if (!bsq->grid)
		return (FALSE);
	i = 0;
	while (i < bsq->size_x)
	{
		bsq->grid[i] = malloc(sizeof(t_uint) * bsq->size_y);
		if (!bsq->grid[i])
		{
			j = 0;
			while (j < i)
				free(bsq->grid[j++]);
			free(bsq->grid);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_uint	current_value(t_bsq *bsq, t_uint x, t_uint y, char c)
{
	t_uint	a;
	t_uint	b;
	t_uint	k;

	a = 0;
	if (x)
		a = bsq->grid[x - 1][y];
	b = 0;
	if (y)
		b = bsq->grid[x][y - 1];
	k = 0;
	if (x && y)
		k = bsq->grid[x - 1][y - 1];
	return (a + b - k + (c == bsq->charset.obstacle));
}

t_bool	parse(t_bsq *bsq)
{
	t_str	fc;
	t_uint	x;
	t_uint	y;
	char	c;

	if (!allocgrid(bsq))
		return (FALSE);
	fc = bsq->file.content + bsq->padstart;
	y = 0;
	while (y < bsq->size_y)
	{
		x = 0;
		while (x < bsq->size_x)
		{
			c = fc[y * (bsq->size_x + 1) + x];
			bsq->grid[x][y] = current_value(bsq, x, y, c);
			x++;
		}
		y++;
	}
	return (TRUE);
}
