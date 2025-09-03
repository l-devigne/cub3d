/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wall_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:23:57 by meruem            #+#    #+#             */
/*   Updated: 2025/08/30 19:07:55 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	choose_wall_textures(t_data *data, t_ray ray)
{
	char	*texture;

	if (ray.type_side == 0 && ray.ray_dir->x > 0)
		texture = data->map->west_texture;
	else if (ray.type_side == 0 && ray.ray_dir->x < 0)
		texture = data->map->east_texture;
	else if (ray.type_side == 1 && ray.ray_dir->y > 0)
		texture = data->map->north_texture;
	else
		texture = data->map->south_texture;
	data->map->wall_path_choice = texture;
}

void	texture_handling(t_data *data, t_ray ray, float real_wall_dist)
{
	float	wall_x;

	if (data->text->tex_img)
		mlx_destroy_image(data->mlx, data->text->tex_img);
	data->text->tex_img = mlx_xpm_file_to_image(data->mlx,
			data->map->wall_path_choice, &data->text->width,
			&data->text->height);
	data->text->tex_addr = mlx_get_data_addr(data->text->tex_img,
			&data->text->bpp, &data->text->line_len, &data->text->endian);
	if (ray.type_side == 0)
		wall_x = ray.ray_origin.y + real_wall_dist * ray.ray_dir->y;
	else
		wall_x = ray.ray_origin.x + real_wall_dist * ray.ray_dir->x;
	wall_x -= floor(wall_x);
	data->text->tex_x = (int)(wall_x * (float)data->text->width);
	if (ray.type_side == 0 && ray.ray_dir->x > 0)
		data->text->tex_x = data->text->width - data->text->tex_x - 1;
	if (ray.type_side == 1 && ray.ray_dir->y < 0)
		data->text->tex_x = data->text->width - data->text->tex_x - 1;
}
