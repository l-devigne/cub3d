/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:08:36 by meruem            #+#    #+#             */
/*   Updated: 2025/09/02 20:27:25 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	detect_key_press(int keysym, t_data *data)
{
	if (keysym == 65307)
		close_window(data);
	else if (keysym == 65361)
		data->keys->key_left = 1;
	else if (keysym == 65363)
		data->keys->key_right = 1;
	else if (keysym == 119)
		data->keys->key_w = 1;
	else if (keysym == 115)
		data->keys->key_s = 1;
	else if (keysym == 97)
		data->keys->key_a = 1;
	else if (keysym == 100)
		data->keys->key_d = 1;
	return (0);
}

int	detect_key_release(int keysym, t_data *data)
{
	if (keysym == 65361)
		data->keys->key_left = 0;
	else if (keysym == 65363)
		data->keys->key_right = 0;
	else if (keysym == 119)
		data->keys->key_w = 0;
	else if (keysym == 115)
		data->keys->key_s = 0;
	else if (keysym == 97)
		data->keys->key_a = 0;
	else if (keysym == 100)
		data->keys->key_d = 0;
	return (0);
}

int	handle_keys(t_data *data)
{
	if (data->keys->key_left)
		rotate_left(data);
	else if (data->keys->key_right)
		rotate_right(data);
	else if (data->keys->key_w)
		move_forward(data);
	else if (data->keys->key_s)
		move_backward(data);
	else if (data->keys->key_a)
		move_left(data);
	else if (data->keys->key_d)
		move_right(data);
	draw_whole_screen(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}
