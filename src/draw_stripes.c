/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:30:31 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/02 22:39:17 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_pixel_texture(t_data *data, int line_height, int index, int i)
{
	int		d;
	int		tex_y;
	char	*pixel;
	int		color;
	int		safe_tex_x;

	if (!data || !data->text || !data->text->tex_addr || line_height <= 0)
		return ;
	d = (i * 256 - data->screen_height * 128 + line_height * 128);
	tex_y = ((d * data->text->height) / line_height) / 256;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= data->text->height)
		tex_y = data->text->height - 1;
	safe_tex_x = data->text->tex_x;
	if (safe_tex_x < 0)
		safe_tex_x = 0;
	if (safe_tex_x >= data->text->width)
		safe_tex_x = data->text->width - 1;
	pixel = data->text->tex_addr + (tex_y * data->text->line_len + safe_tex_x
			* (data->text->bpp / 8));
	color = *(unsigned int *)pixel;
	put_pixel_image(data->img, index, i, color);
}

void	draw_stripe(t_data *data, float cam_step, int index)
{
	int		i;
	float	real_wall_dist;
	int		start;
	int		end;
	int		line_height;

	real_wall_dist = ray_dda_algo(data, cam_step);
	start = draw_start_wall(data, real_wall_dist);
	end = draw_end_wall(data, real_wall_dist);
	line_height = end - start;
	if (line_height <= 0)
		line_height = 1;
	i = 0;
	while (i < data->screen_height)
	{
		if (i < start)
			put_pixel_image(data->img, index, i, data->map->ceiling_color);
		else if (i >= start && i <= end)
		{
			draw_pixel_texture(data, line_height, index, i);
		}
		else
			put_pixel_image(data->img, index, i, data->map->floor_color);
		++i;
	}
}

void	draw_whole_screen(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->screen_width)
	{
		draw_stripe(data, camera_choice(data->screen_width, i), i);
		++i;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
