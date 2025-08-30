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

void choose_wall_textures(int side, t_data *data, t_coord *ray_dir)
{
    char* texture;
    
    if (side == 0 && ray_dir->x > 0)
        texture = data->map->west_texture; // pure green
    else if (side == 0 && ray_dir->x < 0)
        texture = data->map->east_texture; // dark grey
    else if (side == 1 && ray_dir->y > 0)
        texture = data->map->north_texture; // cyan
    else
        texture = data->map->south_texture; // black
    data->map->wall_path_choice = texture;
}

void texture_handling(t_data *data, char *texture_path, int side, t_ray ray, float perpWallDist)
{
    if(data->text->tex_img)
        mlx_destroy_image(data->mlx, data->text->tex_img);
    data->text->tex_img = mlx_xpm_file_to_image(data->mlx, texture_path, &data->text->width, &data->text->height);
    if (!data->text->tex_img)
    {
        printf("Error: could not load texture\n");
        exit(1);
    }
    
    data->text->tex_addr = mlx_get_data_addr(data->text->tex_img, &data->text->bpp, &data->text->line_len, &data->text->endian);

    float wallX; // exact hit coordinate on the wall
    if (side == 0)
        wallX = ray.ray_origin.y + perpWallDist * ray.ray_dir->y;
    else
        wallX = ray.ray_origin.x + perpWallDist * ray.ray_dir->x;
    wallX -= floor(wallX); // keep only the fractional part [0,1)

    data->text->texX = (int)(wallX * (float)data->text->width);

    if (side == 0 && ray.ray_dir->x > 0) data->text->texX = data->text->width - data->text->texX - 1;
    if (side == 1 && ray.ray_dir->y < 0) data->text->texX = data->text->width - data->text->texX - 1;

}

