/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:01:23 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:01:43 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	display_grid(char **grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			printf("tab[%d][%d]:%c | ", i, j, grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	display_map(t_map *map)
{
	if (map->map_path)
		printf("File name : %s\n", map->map_path);
	if (map->east_texture)
		printf("E: %s", map->east_texture);
	if (map->north_texture)
		printf("N: %s", map->north_texture);
	if (map->south_texture)
		printf("S: %s", map->south_texture);
	if (map->west_texture)
		printf("W: %s", map->west_texture);
	printf("Floor color : %d\n", map->floor_color);
	printf("Ceiling color : %d\n", map->ceiling_color);
	printf("Grid starts at line %d\n", map->num_of_lines_to_skip);
	display_grid(map->grid);
}
