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

void	draw_pixel_texture(t_data *data, int line_height, int index, int i)
{
	int		d;
	int		tex_y;
	char	*pixel;
	int		color;

	d = (i * 256 - data->screen_height * 128 + line_height * 128);
	tex_y = ((d * data->text->height) / line_height) / 256;
	pixel = data->text->tex_addr + (tex_y * data->text->line_len
			+ data->text->texX * (data->text->bpp / 8));
	color = *(unsigned int *)pixel;
	put_pixel_image(data->img, index, i, color);
}

void	draw_stripe(t_data *data, float cam_step, int index)
{
	int		i;
	float	perp_wall_dist;
	int		start;
	int		end;
	int		line_height;

	perp_wall_dist = ray_dda_algo(data, cam_step);
	start = draw_start_wall(data, perp_wall_dist);
	end = draw_end_wall(data, perp_wall_dist);
	i = 0;
	while (i < data->screen_height)
	{
		if (i < start)
			put_pixel_image(data->img, index, i, data->map->ceiling_color);
		else if (i >= start && i <= end)
		{
			line_height = end - start;
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
