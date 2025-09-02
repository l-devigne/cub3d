/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_only_valid_chars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:32:15 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:36:19 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_get_only_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map || !map->grid)
		return (false);
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (!(map->grid[i][j] == 'W' || map->grid[i][j] == 'N'
					|| map->grid[i][j] == 'S' || map->grid[i][j] == 'E'
					|| map->grid[i][j] == ' ' || map->grid[i][j] == '\n'
					|| map->grid[i][j] == '0' || map->grid[i][j] == '1'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

