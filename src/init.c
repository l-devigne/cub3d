/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:36 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:42 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	initialize_image(void *mlx, int width, int height)
{
	t_img	img;

	img.mlx_img = mlx_new_image(mlx, width, height);
	if (!(img.mlx_img))
		return (img);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,
			&img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

void	init_player(t_data *data, char **grid, t_player *player)
{
	char	player_look;

	player_look = find_player_in_grid(player, grid);
	if (player_look == 'N')
		player_look_north(player);
	else if (player_look == 'S')
		player_look_south(player);
	else if (player_look == 'W')
		player_look_west(player);
	else
		player_look_east(player);
	data->player = player;
}

void	init_keys(t_data *data, t_keys *keys)
{
	keys->key_a = 0;
	keys->key_d = 0;
	keys->key_w = 0;
	keys->key_s = 0;
	keys->key_left = 0;
	keys->key_right = 0;
	data->keys = keys;
}

void	init_data_null(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->text = NULL;
}
