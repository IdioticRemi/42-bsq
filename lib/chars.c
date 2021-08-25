/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:18 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/23 18:17:18 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <bsq.h>

t_bool	ft_strhasc(t_str charset, char c)
{
	t_uint	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (TRUE);
	return (FALSE);
}

t_bool	ft_charbtw(char c, char min, char max)
{
	return (c >= min && c <= max);
}
