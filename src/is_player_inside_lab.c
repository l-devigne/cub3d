/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_inside_lab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:33:32 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:35:51 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_player_inside_lab(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'W' || map->grid[i][j] == 'N'
			|| map->grid[i][j] == 'S' || map->grid[i][j] == 'E')
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
