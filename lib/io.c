/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:19 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/25 05:25:54 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <bsq.h>

t_str	ft_realloc(t_str	old, t_str	buf, long old_len, long buf_len)
{
	t_str	new;
	long	i;
	long	j;

	j = 0;
	i = 0;
	new = malloc(old_len + buf_len + 1);
	while (i < old_len)
		new[j++] = old[i++];
	free(old);
	i = 0;
	while (i < buf_len)
		new[j++] = buf[i++];
	new[j] = '\0';
	return (new);
}

t_file	ft_stdinread(void)
{
	t_file	file;
	int		stat;
	char	buf[(int) 1e6];

	file.path = "STDIN_INPUT";
	file.length = 0;
	file.content = malloc(1);
	if (!file.content)
		return (file);
	file.content[0] = '\0';
	stat = 1;
	while (stat != 0)
	{
		stat = read(0, buf, 1000000);
		buf[stat] = '\0';
		file.content = ft_realloc(file.content, buf, file.length, stat);
		file.length += stat;
	}
	return (file);
}

t_bool	ft_file_exists(t_str path)
{
	int		fd;
	t_bool	res;

	fd = open(path, O_RDONLY);
	res = TRUE;
	if (fd == -1)
		res = FALSE;
	close(fd);
	return (res);
}

long	ft_filelen(t_str path)
{
	long	filelen;
	int		t;
	int		fd;
	char	buf[(int) 1e6];

	if (!ft_file_exists(path))
		return (0);
	fd = open(path, O_RDONLY);
	t = read(fd, buf, (int) 1e6);
	filelen = t;
	while (t != 0)
	{
		t = read(fd, buf, (int) 1e6);
		filelen += t;
	}
	close(fd);
	return (filelen);
}

t_file	ft_fileread(t_str path)
{
	t_file	file;
	int		fd;

	file.path = path;
	file.length = ft_filelen(path);
	file.content = malloc(file.length + 1);
	if (!file.content)
		return (file);
	fd = open(path, O_RDONLY);
	if (ft_file_exists(path))
		read(fd, file.content, file.length);
	close(fd);
	file.content[file.length] = '\0';
	return (file);
}
