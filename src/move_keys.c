/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:11:38 by meruem            #+#    #+#             */
/*   Updated: 2025/09/02 22:49:18 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_data *data)
{
	float	temp_new_x;
	float	temp_new_y;

	temp_new_x = data->player->x + data->player->dir_x * 0.15;
	temp_new_y = data->player->y + data->player->dir_y * 0.15;
	if (!move_to_wall(data, temp_new_x, temp_new_y))
	{
		printf("new x is %f and new y is %f\n", data->player->x, data->player->y);
		data->player->x = data->player->x + data->player->dir_x * 0.15;
		data->player->y = data->player->y + data->player->dir_y * 0.15;
	}
}

void	move_backward(t_data *data)
{
	float	temp_new_x;
	float	temp_new_y;

	temp_new_x = data->player->x - data->player->dir_x * 0.15;
	temp_new_y = data->player->y - data->player->dir_y * 0.15;
	if (!move_to_wall(data, temp_new_x, temp_new_y))
	{
		printf("new x is %f and new y is %f\n", data->player->x, data->player->y);
		data->player->x = data->player->x - data->player->dir_x * 0.15;
		data->player->y = data->player->y - data->player->dir_y * 0.15;
	}
}

void	move_left(t_data *data)
{
	float	temp_new_x;
	float	temp_new_y;

	temp_new_x = data->player->x - (-data->player->dir_y) * 0.15;
	temp_new_y = data->player->y - data->player->dir_x * 0.15;
	if (!move_to_wall(data, temp_new_x, temp_new_y))
	{
		printf("new x is %f and new y is %f\n", data->player->x, data->player->y);
		data->player->x = data->player->x - (-data->player->dir_y) * 0.15;
		data->player->y = data->player->y - data->player->dir_x * 0.15;
	}
}

void	move_right(t_data *data)
{
	float	temp_new_x;
	float	temp_new_y;

	temp_new_x = data->player->x + (-data->player->dir_y) * 0.15;
	temp_new_y = data->player->y + data->player->dir_x * 0.15;
	if (!move_to_wall(data, temp_new_x, temp_new_y))
	{
		printf("new x is %f and new y is %f\n", data->player->x, data->player->y);
		data->player->x = data->player->x + (-data->player->dir_y) * 0.15;
		data->player->y = data->player->y + data->player->dir_x * 0.15;
	}
}
