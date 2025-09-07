/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:04:46 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/07 19:56:16 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_cases(t_data *data, t_map *map, int fd)
{
	if (!map->north_texture || !map->south_texture
		|| !map->east_texture || !map->west_texture)
	{
		close (fd);
		ft_clear_all(data, 1);
		return ;
	}
	close (fd);
}

int	handle_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

void	get_textures(t_data *data, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = get_safe_fd(map->map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		i = handle_spaces(line);
		if (!ft_strncmp(line + i, "NO ", 3))
			map->north_texture = get_str_without_eol(line + 3 + i, data);
		else if (!ft_strncmp(line + i, "SO ", 3))
			map->south_texture = get_str_without_eol(line + 3 + i, data);
		else if (!ft_strncmp(line + i, "WE ", 3))
			map->west_texture = get_str_without_eol(line + 3 + i, data);
		else if (!ft_strncmp(line + i, "EA ", 3))
			map->east_texture = get_str_without_eol(line + 3 + i, data);
		else if (!ft_strncmp(line + i, "F ", 2))
			map->floor_color = get_color_from_string(line + 2 + i);
		else if (!ft_strncmp(line + i, "C ", 2))
			map->ceiling_color = get_color_from_string(line + 2 + i);
		free(line);
		line = get_next_line(fd);
	}
	check_cases(data, map, fd);
}
