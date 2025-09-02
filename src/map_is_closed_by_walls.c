/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_closed_by_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:34:08 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:35:48 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_is_closed_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '0')
			{
				if (check_left(map, i, j) == -1 || check_right(map, i, j) == -1
					|| check_up(map, i, j) == -1 || check_down(map, i, j) == -1)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
