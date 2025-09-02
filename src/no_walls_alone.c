/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_walls_alone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:45:07 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:45:19 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	no_walls_alone(const char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '0' || line[0] == '1')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (!ft_strcmp(line, "\n"))
			return (free(line), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}
