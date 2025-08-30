/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:35:24 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/30 18:04:24 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_step_map_grid(t_ray *ray)
{
    if (ray->ray_dir->x < 0)
    { 
        ray->step_map.x = -1; 
        ray->side_dist.x = (ray->ray_origin.x - ray->ray_map_origin_x) * ray->dist_next_cel.x; 
    }
    else
    {
        ray->step_map.x = +1; 
        ray->side_dist.x = (ray->ray_map_origin_x + 1.0 - ray->ray_origin.x) * ray->dist_next_cel.x;
    }
    if (ray->ray_dir->y < 0) 
    { 
        ray->step_map.y = -1; 
        ray->side_dist.y = (ray->ray_origin.y - ray->ray_map_origin_y) * ray->dist_next_cel.y;
    }
    else 
    {
        ray->step_map.y = +1; 
        ray->side_dist.y = (ray->ray_map_origin_y + 1.0 - ray->ray_origin.y) * ray->dist_next_cel.y; 
    }
}

int which_side_hit(t_data *data, t_ray *ray)
{
    int hit;
    int side;

    hit = 0;
    while (hit == 0)
    {
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->dist_next_cel.x;
            ray->ray_map_origin_x += ray->step_map.x;
            side = 0;
        }
        else
        {
            ray->side_dist.y += ray->dist_next_cel.y;
            ray->ray_map_origin_y += ray->step_map.y;
            side = 1;
        }
        if (data->map->grid[ray->ray_map_origin_y][ray->ray_map_origin_x] == '1')
            hit = 1;
    }
    return (side);
}

void init_ray(t_ray *ray, t_data *data, float cam_step)
{
    ray->ray_dir = ray_direction(data->player, cam_step);
    ray->ray_origin.x = data->player->x;
    ray->ray_origin.y = data->player->y;
    ray->ray_map_origin_x = (int)ray->ray_origin.x;
    ray->ray_map_origin_y = (int)ray->ray_origin.y;
    ray->dist_next_cel.x = fabs(1 / ray->ray_dir->x);
    ray->dist_next_cel.y = fabs(1 / ray->ray_dir->y);
    init_step_map_grid(ray);
}
