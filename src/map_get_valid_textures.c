/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_valid_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:31:06 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:36:07 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_get_valid_textures(t_map *map)
{
	if (!map->north_texture || !map->south_texture || !map->west_texture
		|| !map->east_texture)
		return (false);
	if (!textures_are_in_valid_format(map->north_texture)
		|| !textures_are_in_valid_format(map->south_texture)
		|| !textures_are_in_valid_format(map->east_texture)
		|| !textures_are_in_valid_format(map->west_texture))
		return (false);
	if (get_safe_fd(map->north_texture, CLOSE) < 0
		|| get_safe_fd(map->south_texture, CLOSE) < 0
		|| get_safe_fd(map->west_texture, CLOSE) < 0
		|| get_safe_fd(map->east_texture, CLOSE) < 0)
		return (false);
	return (true);
}
