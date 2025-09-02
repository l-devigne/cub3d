/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stay_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:55:11 by meruem            #+#    #+#             */
/*   Updated: 2025/09/01 22:46:51 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	move_to_wall(t_data *data, float new_x, float new_y)
{
	int mapx;
	int mapy;

	mapx = (int)new_x;
	mapy = (int)new_y;
	if (!(data->map->grid[mapy][mapx]) || data->map->grid[mapy][mapx] == '1')
		return (1);
	return (0);
}