/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_valid_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:32:48 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:36:10 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_get_valid_player(t_map *map)
{
	int	player_num;
	int	i;
	int	j;

	if (!map || !map->grid)
		return (false);
	player_num = 0;
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'W' || map->grid[i][j] == 'N'
				|| map->grid[i][j] == 'S' || map->grid[i][j] == 'E')
				player_num++;
			j++;
		}
		i++;
	}
	if (player_num == 1)
		return (is_player_inside_lab(map));
	return (false);
}
