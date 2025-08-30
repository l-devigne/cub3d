/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_turn_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:11:17 by meruem            #+#    #+#             */
/*   Updated: 2025/08/30 23:28:36 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rotate_left(t_data *data)
{
    float old_dir_x = data->player->dir_x;
    float old_plane_x = data->player->plane_x;

    // rotate direction
    data->player->dir_x = data->player->dir_x * cos(-0.1) - data->player->dir_y * sin(-0.1);
    data->player->dir_y = old_dir_x * sin(-0.1) + data->player->dir_y * cos(-0.1);

    // rotate camera plane as well
    data->player->plane_x = data->player->plane_x * cos(-0.1) - data->player->plane_y * sin(-0.1);
    data->player->plane_y = old_plane_x * sin(-0.1) + data->player->plane_y * cos(-0.1);

}

void rotate_right(t_data *data)
{
    float old_dir_x = data->player->dir_x;
    float old_plane_x = data->player->plane_x;

    // rotate direction
    data->player->dir_x = data->player->dir_x * cos(0.1) - data->player->dir_y * sin(0.1);
    data->player->dir_y = old_dir_x * sin(0.1) + data->player->dir_y * cos(0.1);

    // rotate camera plane as well
    data->player->plane_x = data->player->plane_x * cos(0.1) - data->player->plane_y * sin(0.1);
    data->player->plane_y = old_plane_x * sin(0.1) + data->player->plane_y * cos(0.1);

}
