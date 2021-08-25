/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:37:10 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/25 05:03:37 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_bool	print_error(void)
{
	ft_putstr("map error\n");
	return (1);
}

t_bool	pas_un_moyen_de_raccourcir_le_code(t_bsq *bsq)
{
	free(bsq->file.content);
	return (print_error());
}

int	main(int argc, char **argv)
{
	t_bsq	bsq;
	t_bool	valid;
	int		i;

	i = -1;
	while (++i < argc)
	{
		if (argc == 1)
			bsq.file = ft_stdinread();
		else if (i != 0 && ft_file_exists(argv[i]))
			bsq.file = ft_fileread(argv[i]);
		else
			continue ;
		valid = verif_all_grid(bsq.file.content, &bsq, 0, 0);
		if (!valid)
			return (pas_un_moyen_de_raccourcir_le_code(&bsq));
		bsq.padstart = ft_strulen(bsq.file.content, "\n") + 1;
		parse(&bsq);
		run_algo(&bsq);
		ft_print_tab(&bsq);
		free(bsq.file.content);
		free_grid(&bsq);
	}
}
