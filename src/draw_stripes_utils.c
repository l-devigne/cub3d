/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:34:56 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/02 22:39:17 by ldevigne         ###   ########.fr       */
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

	// Vérifications de sécurité pour éviter les accès hors limites
	if (!img.addr || x < 0 || y < 0 || x >= img.width || y >= img.height)
		return;
	
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
// add textures later
