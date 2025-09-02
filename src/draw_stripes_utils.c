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

int	screen_wall_height(t_data *data, float perpWallDist)
{
	return ((int)(data->screen_height / perpWallDist));
}

int	draw_start_wall(t_data *data, float perpWallDist)
{
	int	draw_start;

	draw_start = -screen_wall_height(data, perpWallDist) / 2
		+ data->screen_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	draw_end_wall(t_data *data, float perpWallDist)
{
	int	draw_end;

	draw_end = screen_wall_height(data, perpWallDist) / 2 + data->screen_height
		/ 2;
	if (draw_end < 0)
		draw_end = 0;
	return (draw_end);
}

void	put_pixel_image(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
// add textures later
