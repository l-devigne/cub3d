/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_and_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:10:37 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:10:59 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	process_to_eof(char **line, int *x, int fd)
{
	int		i;
	char	*tmp;

	tmp = *line;
	while (tmp)
	{
		i = 0;
		while (tmp[i])
			i++;
		if (i > *x)
			*x = i;
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	get_x_len(const char *map_path)
{
	char	*line;
	int		fd;
	int		x;
	int		nb_to_skip;

	x = 0;
	nb_to_skip = get_lines_num_to_skip(map_path);
	fd = get_safe_fd(map_path, KEEP_OPEN);
	while (nb_to_skip-- > 0)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	process_to_eof(&line, &x, fd);
	return (close(fd), x);
}

int	get_y_len(const char *map_path)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = get_safe_fd(map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	y -= get_lines_num_to_skip(map_path);
	return (close(fd), y);
}
