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

void	draw_stripe(t_data *data, float cam_step, int index)
{
	int		i;
	float	perpWallDist;
	int		start;
	int		end;
	int		lineHeight;
	int		d;
	int		texY;
	char	*pixel;
	int		color;

	perpWallDist = ray_dda_algo(data, cam_step);
	start = draw_start_wall(data, perpWallDist);
	end = draw_end_wall(data, perpWallDist);
	i = 0;
	while (i < data->screen_height)
	{
		if (i < start)
			put_pixel_image(data->img, index, i, data->map->ceiling_color);
		else if (i >= start && i <= end)
		{
			lineHeight = end - start;
			d = (i * 256 - data->screen_height * 128 + lineHeight * 128);
			texY = ((d * data->text->height) / lineHeight) / 256;
			pixel = data->text->tex_addr + (texY * data->text->line_len
					+ data->text->texX * (data->text->bpp / 8));
			color = *(unsigned int *)pixel;
			put_pixel_image(data->img, index, i, color);
			// put_pixel_image(data->img, index, i, data->map->wall_color);
		}
		else
			put_pixel_image(data->img, index, i, data->map->floor_color);
		++i;
	}
}

void	draw_whole_screen(t_data *data)
{
	int i;

	i = 0;
	while (i < data->screen_width)
	{
		draw_stripe(data, cameraX_choice(data->screen_width, i), i);
		++i;
	}
}