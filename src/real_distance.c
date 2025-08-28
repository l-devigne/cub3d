/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:29:54 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/28 16:35:49 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float grid_dist_wall(t_ray ray)
{
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
    else
        perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
}   