/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:30:31 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/29 15:44:33 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_stripe(t_data *data, float cam_step, int index)
{
    int i;
    float perpWallDist = ray_dda_algo(data, cam_step);
    int start = draw_start_wall(data, perpWallDist);
    int end = draw_end_wall(data, perpWallDist);

    i = 0;
    while(i < data->screen_height)
    {
        if (i < start)
        {
            // ceiling
            put_pixel_image(data->img, index, i, data->map->ceiling_color);
        }
        else if (i >= start && i <= end)
        {
            // wall (use texture sampling here, simple example = solid color)
            put_pixel_image(data->img, index, i, data->map->wall_color);
        }
        else
        {
            // floor
            put_pixel_image(data->img, index, i, data->map->floor_color);
        }
        ++i;
    }
}

void draw_whole_screen(t_data *data)
{
    int i;

    i = 0;
    while(i < data->screen_width)
    {
        draw_stripe(data, cameraX_choice(data->screen_width, i), i);
        ++i;
    }
}