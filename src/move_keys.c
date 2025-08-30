/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:11:38 by meruem            #+#    #+#             */
/*   Updated: 2025/08/30 23:19:33 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void move_forward(t_data *data)
{
    data->player->x += data->player->dir_x * 0.1;
    data->player->y += data->player->dir_y * 0.1;
}

void move_backward(t_data *data)
{
    data->player->x -= data->player->dir_x * 0.1;
    data->player->y -= data->player->dir_y * 0.1;
}

void move_left(t_data *data)
{
    data->player->x -= -data->player->dir_y * 0.1;
    data->player->y -= data->player->dir_x * 0.1;
}

void move_right(t_data *data)
{
    data->player->x += -data->player->dir_y * 0.1;
    data->player->y += data->player->dir_x * 0.1;
}