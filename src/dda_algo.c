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
    float rayPosX = data->player->x;
    float rayPosY = data->player->y; 
    int mapX = (int)rayPosX;
    int mapY = (int)rayPosY;
    float deltaDistX;
    float deltaDistY;
    t_coord dir;
    t_coord plane;
    dir.x = data->player->dir_x;
    dir.y = data->player->dir_y;
    plane.x = data->player->plane_x;
    plane.y = data->player->plane_y;
    t_coord *ray_dir = ray_direction(dir, plane, cam_step);
    deltaDistX = fabs(1 / ray_dir->x);
    deltaDistY = fabs(1 / ray_dir->y);
    int stepX;
    int stepY;
    float sideDistX;
    float sideDistY;
    int hit = 0;
    int side; // 0 = x-side, 1 = y-side
    double perpWallDist;


    if (ray_dir->x < 0)
    { 
        stepX = -1; 
        sideDistX = (rayPosX - mapX) * deltaDistX; 
    }
    else
    {
        stepX = +1; 
        sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
    }
    if (ray_dir->y < 0) 
    { 
        stepY = -1; 
        sideDistY = (rayPosY - mapY) * deltaDistY;
    }
    else 
    { 
        stepY = +1; 
        sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY; 
    }


    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        if (data->map->grid[mapY][mapX] == '1')
            hit = 1;
    }
    

    if (side == 0)
        perpWallDist = ((float)mapX - rayPosX + (1 - stepX) / 2) / ray_dir->x;
    else
        perpWallDist = ((float)mapY - rayPosY + (1 - stepY) / 2) / ray_dir->y;
    
    choose_color(side, data, ray_dir);

    return (perpWallDist);
}