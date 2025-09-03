/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:29:06 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/30 18:04:21 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	ray_dda_algo(t_data *data, float cam_step)
{
	t_ray	ray_info;
	float	real_wall_dist;

	init_ray(&ray_info, data, cam_step);
	ray_info.type_side = which_side_hit(data, &ray_info);
	if (ray_info.type_side == 0)
		real_wall_dist = ((float)ray_info.ray_map_origin_x
				- ray_info.ray_origin.x + (1 - ray_info.step_map.x) / 2)
			/ ray_info.ray_dir->x;
	else
		real_wall_dist = ((float)ray_info.ray_map_origin_y
				- ray_info.ray_origin.y + (1 - ray_info.step_map.y) / 2)
			/ ray_info.ray_dir->y;
	choose_wall_textures(data, ray_info);
	texture_handling(data, ray_info, real_wall_dist);
	free(ray_info.ray_dir);
	return (real_wall_dist);
}
