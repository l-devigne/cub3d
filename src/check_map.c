/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:23:44 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/03 14:42:10 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_get_valid_colors(t_map *map)
{
	if (map->ceiling_color < 0 || map->floor_color < 0)
		return (false);
	return (true);
}

bool	check_map(t_map *map)
{
	if (!map_get_valid_textures(map))
		return (printf("Error\n[invalid textures]\n"), false);
	if (!map_get_valid_colors(map))
		return (printf("Error\n[invalid colors]\n"), false);
	if (!map_is_closed_by_walls(map))
		return (printf("Error\n[invalid walls]\n"), false);
	if (!map_get_valid_player(map))
		return (printf("Error\n[invalid player]\n"), false);
	if (!map_get_only_valid_chars(map))
		return (printf("Error\n[invalid items]\n"), false);
	return (true);
}
