/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:38:04 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/27 12:03:32 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_square(const char *pathname)
{
	int		fd;
	char	*line;
	size_t	prev_len;

	fd = open(pathname, O_RDONLY);
	line = get_next_line(fd);// on charge la ligne de notre fichier
	if (!line)
		return (false);
	while (line)
	{
		prev_len = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (true);
		if (ft_strlen(line) != prev_len)
			return (free(line), false);
	}
	return (free(line), true);
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
	while (line)
	{

		free(line);
		line = get_next_line(fd);
		i = 0;
		if (!line)
			return (true);
		while (line[i] && (line[i] == '0' || line[i] == '1' || line[i] == '\n'))
			i++;
		if (i != ft_strlen(line))
			return (free(line), false);
	}
	return (free(line), true);
}
