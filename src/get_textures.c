/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:04:46 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:07:11 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_cases(t_data *data, t_map *map)
{
	if (!map->north_texture || !map->south_texture
		|| !map->east_texture || !map->west_texture
		|| !map->floor_color || !map->ceiling_color)
	{
		ft_clear_all(data, 1);
		return ;
	}
}

void	get_textures(t_data *data, t_map *map)
{
	int		fd;
	char	*line;

	fd = get_safe_fd(map->map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO ", 3))
			map->north_texture = get_str_without_eol(line + 3, data);
		else if (!ft_strncmp(line, "SO ", 3))
			map->south_texture = get_str_without_eol(line + 3, data);
		else if (!ft_strncmp(line, "WE ", 3))
			map->west_texture = get_str_without_eol(line + 3, data);
		else if (!ft_strncmp(line, "EA ", 3))
			map->east_texture = get_str_without_eol(line + 3, data);
		else if (!ft_strncmp(line, "F ", 1))
			map->floor_color = get_color_from_string(line + 2);
		else if (!ft_strncmp(line, "C ", 1))
			map->ceiling_color = get_color_from_string(line + 2);
		free(line);
		line = get_next_line(fd);
	}
	check_cases(data, map);
	close(fd);
}
