/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:28:12 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/28 16:57:33 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	cameraX_choice(int screen_width, float camrange_index)
{
	return (2 * camrange_index / (float)screen_width - 1);
}

t_coord	*ray_direction(t_player *player, float cameraX)
{
	t_coord *ray_dir;

	ray_dir = malloc(sizeof(t_coord));
	if (!ray_dir)
		return (NULL);
	ray_dir->x = player->dir_x + (player->plane_x * cameraX);
	ray_dir->y = player->dir_y + (player->plane_y * cameraX);

	return (ray_dir);
}