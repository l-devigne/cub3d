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

float cameraX_choice(int screen_width, float camrange_index)
{
    return (2 * camrange_index / (float)screen_width - 1);
}

t_coord *ray_direction(t_coord dir, t_coord plane, float cameraX)
{
    t_coord *ray_dir;

    ray_dir = malloc(sizeof(t_coord));
    if(!ray_dir)
        return (NULL);
    ray_dir->x = dir.x + (plane.x * cameraX);
    ray_dir->y = dir.y + (plane.y * cameraX);
    
    return (ray_dir);
}