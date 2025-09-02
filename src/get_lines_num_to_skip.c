/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_num_to_skip.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:41 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:06:57 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	skip_to_end(char **line, int fd)
{
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd);
	}
	if (!*line)
		return ;
}

int	get_lines_num_to_skip(const char *map_path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = get_safe_fd(map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strcmp(line, "\n") || !ft_strncmp(line, "F ", 2)
			|| !ft_strncmp(line, "C ", 2))
		{
			free(line);
			line = get_next_line(fd);
			line_count++;
		}
		else
			break ;
	}
	skip_to_end(&line, fd);
	return (free(line), close(fd), (line_count));
}
