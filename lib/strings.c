/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:21 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/25 03:46:04 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

long	ft_strlen(t_str str)
{
	t_uint	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_strulen(t_str str, t_str charset)
{
	t_uint	i;

	i = 0;
	while (str[i] && !ft_strhasc(charset, str[i]))
		i++;
	return (i);
}

long	ft_strolen(t_str str, t_str charset)
{
	t_uint	i;

	i = 0;
	while (str[i] && ft_strhasc(charset, str[i]))
		i++;
	return (i);
}

long	ft_strcount(t_str str, char c)
{
	long	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	ft_atoi(t_str str, int max_i)
{
	int	x;
	int i;

	x = 0;
	i = 0;
	while (i < max_i && str[i] && ft_charbtw(str[i], '0', '9'))
		x = x * 10 + (str[i++] - '0');
	return (x);
}
