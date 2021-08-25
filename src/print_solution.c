/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:17:15 by kbarbry           #+#    #+#             */
/*   Updated: 2021/08/25 03:02:51 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_tab(t_bsq *bsq)
{
	long i;
	long x;
	long y;

	i = 0;
	while (i < bsq->file.length - bsq->padstart)
	{
		x = i % (bsq->size_x + 1);
		y = i / (bsq->size_x + 1);
		if (x >= bsq->sqr_x && x < bsq->sqr_x + bsq->size
				&& y >= bsq->sqr_y && y < bsq->sqr_y + bsq->size)
			ft_putchar(bsq->charset.fill);
		else
			ft_putchar(bsq->file.content[i + bsq->padstart]);
		i++;
	}
}
