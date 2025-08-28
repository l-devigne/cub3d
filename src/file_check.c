/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:38:04 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/28 12:10:31 by ldevigne         ###   ########.fr       */
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

size_t	get_prev_size_line(char *line, int wall_index)
{
	size_t	i;
	(void) wall_index;

	i = 1;
	while (line[i] && line[i] != '1')
		i++;
	if (!line[i])
		return (0);
	return (i + 1);
}

bool	is_line_full_wall(char *line)
{
	if (!line)
		return (false);
	if (!process_line_check(line))
		return(free(line), false);
	return (true);
}

void	check_left_wall(char *line)
{
	if (line[0] == '1')
		return ;
	else
	{
		free(line);
		ft_error_msg("Missing walls in map\n", 1);
		return ;
	}
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
	printf("First wall line :%s\n", line);
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

bool	only_valid_chars(const char *pathname)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open(pathname, O_RDONLY);
	printf("only_valid_chars function\n");
	line = get_next_line(fd);// on charge la ligne de notre fichier
	printf("%p => %s\n", line, line);
	if (!line)
		return (false);
	i = 0;
	while (line[i] && (line[i] == '0' || line[i] == '1' || line[i] == '\n'))
		i++;
	if (i != ft_strlen(line))
		return (free(line), false);
	printf("(0) all good in only_valid_chars\n");
	while (line)
	{
		printf("i:[%ld]\n", i);
		free(line);
		line = get_next_line(fd);
		i = 0;
		if (!line)
			return (true);
		while (line[i] && (line[i] == '0' || line[i] == '1' || line[i] == '\n'))
			i++;
		if (i != ft_strlen(line))
		{
			printf("i:[%ld] | size:[%ld]\n", i, ft_strlen(line));
			return (free(line), false);
		}
	}
	return (free(line), true);
}
