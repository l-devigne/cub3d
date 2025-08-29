/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:29:06 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/29 16:22:08 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float ray_dda_algo(t_data *data, float cam_step)
{
    t_ray ray_info;
    int side;
    double perpWallDist;

    init_ray(&ray_info, data, cam_step);
    side = which_side_hit(data, &ray_info);
    if (side == 0)
        perpWallDist = ((float)ray_info.ray_map_origin_x - ray_info.ray_origin.x + (1 - ray_info.step_map.x) / 2) / ray_info.ray_dir->x;
    else
        perpWallDist = ((float)ray_info.ray_map_origin_y - ray_info.ray_origin.y + (1 - ray_info.step_map.y) / 2) / ray_info.ray_dir->y;
    
    choose_wall_color(side, data, ray_info.ray_dir);

    return (perpWallDist);
}
