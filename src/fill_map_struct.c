/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:02:24 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/03 15:17:31 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_map_struct(t_data *data, const char *map_path, t_map *map)
{
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->east_texture = NULL;
	map->south_texture = NULL;
	map->north_texture = NULL;
	map->west_texture = NULL;
	map->grid = NULL;
	map->map_path = ft_strdup(map_path);
	if (!map->map_path)
	{
		ft_clear_all(data, 1);
		return ;
	}
	map->num_of_lines_to_skip = get_lines_num_to_skip(map_path);
	map->x_len = get_x_len(map_path);
	map->y_len = get_y_len(map_path);
	get_textures(data, map);
	fill_grid(data, map);
}
