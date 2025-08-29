/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:34:56 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/29 12:19:24 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int screen_wall_height(t_data *data, float perpWallDist)
{
    return ((int)(data->screen_height / perpWallDist));
}

int draw_start_wall(t_data *data, float perpWallDist)
{
    int drawStart;

    drawStart = -screen_wall_height(data, perpWallDist) / 2 + data->screen_height / 2;
    if (drawStart < 0) 
        drawStart = 0;
    return (drawStart);
}

int draw_end_wall(t_data *data, float perpWallDist)
{
    int drawEnd;

    drawEnd = screen_wall_height(data, perpWallDist) / 2 + data->screen_height / 2;
    if (drawEnd < 0)
        drawEnd = 0;
    return (drawEnd);
}

void	put_pixel_image(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
// add textures later

void choose_color(int side, t_data *data, t_coord *ray_dir)
{
    int texture;
    
    if (side == 0 && ray_dir->x > 0)
        texture = 0x00FF00; // pure green
    else if (side == 0 && ray_dir->x < 0)
        texture = 0x404040; // dark grey
    else if (side == 1 && ray_dir->y > 0)
        texture = 0x00FFFF; // cyan
    else
        texture = 0x000000; // black
    data->map->wall_color = texture;
}

