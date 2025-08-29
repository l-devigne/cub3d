/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:38:04 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/29 11:11:45 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	process_line_check(const char *line)
{
	size_t	len_line;
	size_t	i;

	if (!line)
		return (false);
	i = 0;
	len_line = ft_strlen(line);
	while (line && *line)
	{
		if (*line == '1')
			line++;
		else if (*line == '\n')
		{
			i++;
			break;
		}
		else
			break;
		i++;
	}
	if (i == len_line)
		return (true);
	return (false);
}

bool	is_line_full_wall(char *line)
{
	if (!line)
		return (false);
	if (!process_line_check(line))
		return(free(line), false);
	return (true);
}

bool	map_is_closed_by_walls(const char *pathname)
{
	int		fd;
	size_t	i;
	char	*line;
	char	*last_line;
	size_t	prev_size_line;
	size_t	len;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (false);
	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);// premiere ligne
		free(line);
		i++;
	}
	line = get_next_line(fd);// premiere ligne
	if (!is_line_full_wall(line))
		return (close(fd), false);
	prev_size_line = ft_strlen(line);// on se rappelle de la taille du premier mur
	last_line = ft_strdup(line);
	free(line);
	line = get_next_line(fd);// on charge la prochaine ligne a analyser
	while (line)
	{
		len = ft_strlen(line);
		if (line[0] != '1')
			return (free(line), free(last_line), close(fd), false);
		
		if (len > 1 && line[len - 2] != '1')
			return (free(line), free(last_line), close(fd), false);

		if (len > prev_size_line)
		{
			i = prev_size_line - 1;
			while (i < len - 1)
			{
				if (line[i] != '1')
					return (free(line), free(last_line), close(fd), false);
				i++;
			}
		}
		else if (len < prev_size_line)
		{
			i = len - 1;
			while (i < prev_size_line - 1)
			{
				if (last_line[i] != '1')
					return (free(line), free(last_line), close(fd), false);
				i++;
			}
		}
		free(last_line);
		last_line = ft_strdup(line);
		prev_size_line = len;
		free(line);
		line = get_next_line(fd);
	}
	if (!is_line_full_wall(last_line))
		return (free(last_line), close(fd), false);
	return(free(last_line), close(fd), true);
}
