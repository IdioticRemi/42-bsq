/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_grid_opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:34:16 by kbarbry           #+#    #+#             */
/*   Updated: 2021/08/25 03:54:21 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

long	ft_nbrlen(long nbr)
{
	long l;

	l = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		l++;
	}
	return (l);
}

t_bool	verif_first_line(t_str str, t_bsq *data) //ENVOYER SEULEMENT LA PREMIERE LIGNE
{
	long	i;
	long	j;

	i = ft_strulen(str, "\n") - 1;
	j = i;
	data->size_y = ft_atoi(str, i - 2);
	if (ft_nbrlen(data->size_y) + 2 != i)
		return (FALSE);
	if (data->size_y <= 0)
		return (FALSE);
	while (i > j - 3)
	{
		if (!ft_charbtw(str[i], 32, 126))
			return (FALSE);
		i--;
	}
	if (str[j] == str[j - 1] || str[j - 1] == str[j - 2]
	|| str[j] == str[j - 2])
		return (FALSE);
	data->charset.empty = str[j - 2];
	data->charset.obstacle = str[j - 1];
	data->charset.fill = str[j];
	return (TRUE);
}

t_bool	verif_size_line(long size_line, t_bsq *data)
{
	if (size_line < 1)
		return (FALSE);
	else if (size_line != data->size_x)
			return (FALSE);
	return (TRUE);
}

t_bool	verif_all_grid(t_str str, t_bsq *data, long count_line, long size_line)
{
	int i;

	if (!verif_first_line(str, data))
		return (FALSE);
	data->padstart = ft_strulen(str, "\n");
	i = data->padstart + 1;
	data->size_x = ft_strulen(str + i, "\n");
	while (str[i] != '\0')
	{
		size_line = 0;
		while (str[i] != '\n')
		{
			if (str[i] != data->charset.obstacle
				&& str[i] != data->charset.empty)
				return(FALSE);
			size_line++;
			i++;
		}
		i++;
		if (!verif_size_line(size_line, data))
			return (FALSE);
		count_line++;
	}
	return (count_line == data->size_y);
}
