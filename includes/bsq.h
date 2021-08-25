/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 04:20:21 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/25 05:03:37 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H

// Defines

# define TRUE	1
# define FALSE	0

// Standard libraries

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// Typedefs

typedef int				t_bool;
typedef char *			t_str;
typedef unsigned int	t_uint;
typedef t_uint **		t_matrix;

// Custom structures

typedef struct s_file {
	t_str	path;
	t_str	content;
	long	length;
}	t_file;

typedef struct s_charset {
	char	obstacle;
	char	empty;
	char	fill;
}	t_charset;

typedef struct s_bsq {
	t_charset	charset;
	t_matrix	grid;
	long		sqr_x;
	long		sqr_y;
	long		size_x;
	long		size_y;
	long		size;
	long		padstart;
	t_file		file;
}	t_bsq;

t_bool	parse(t_bsq *bsq);
void	run_algo(t_bsq *bsq);
void	ft_print_tab(t_bsq *bsq, long i, long x, long y);

//verif_grid_opti.c

t_bool	verif_all_grid(t_str str, t_bsq *data, long count_line, long size_line);

// lib

t_bool	ft_strhasc(t_str charset, char c);
t_bool	ft_charbtw(char c, char min, char max);

int		ft_atoi(t_str str, int max_i);
long	ft_strlen(t_str str);
long	ft_strcount(t_str str, char c);
long	ft_strulen(t_str str, t_str charset);
long	ft_strolen(t_str str, t_str charset);

t_str	ft_cut_string(t_str str, char c);

void	ft_putstr(t_str str);
void	ft_putchar(char c);

t_file	ft_stdinread(void);
t_file	ft_fileread(t_str path);
t_bool	ft_file_exists(t_str path);

void	free_grid(t_bsq *bsq);

#endif
