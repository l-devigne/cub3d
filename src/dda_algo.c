/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:29:06 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/28 19:01:48 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

ray_dda_algo(t_data *data)
{
    float rayPosX = data->player->x;
    float rayPosY = data->player->y;
    int mapX = (int)rayPosX;
    int mapY = (int)rayPosY;
    float deltaDistX = fabs(1 / data->player->dir_x);
    float deltaDistY = fabs(1 / data->player->dir_y);
    int stepX;
    int stepY;
    float sideDistX;
    float sideDistY;
    int hit = 0;
    int side; // 0 = x-side, 1 = y-side
    double perpWallDist;


    if (data->player->dir_x < 0)
    { 
        stepX = -1; 
        sideDistX = (rayPosX - mapX) * deltaDistX; 
    }
    else
    {
        stepX = +1; 
        sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
    }
    if (data->player->dir_y < 0) 
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
        perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
    else
        perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
}