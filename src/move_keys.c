/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meruem <meruem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:11:38 by meruem            #+#    #+#             */
/*   Updated: 2025/08/30 19:37:35 by meruem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void move_forward(t_data *data)
{
    data->player->x += data->player->dir_x * 0.1;
    data->player->y += data->player->dir_y * 0.1;
    draw_whole_screen(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 50, 50);
}

void move_backward(t_data *data)
{
    data->player->x -= data->player->dir_x * 0.1;
    data->player->y -= data->player->dir_y * 0.1;
    draw_whole_screen(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 50, 50);
}

void move_left(t_data *data)
{
    data->player->x -= -data->player->dir_y * 0.1;
    data->player->y -= data->player->dir_x * 0.1;
    draw_whole_screen(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 50, 50);
}

void move_right(t_data *data)
{
    data->player->x += -data->player->dir_y * 0.1;
    data->player->y += data->player->dir_x * 0.1;
    draw_whole_screen(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 50, 50);
}

int handle_keys(int keysym, t_data *data)
{
    if (keysym == 65307) // Escape
        close_window(data);
    if (keysym == 65361) // left arrow
        rotate_left(data);
    if (keysym == 65363) // right arrow
        rotate_right(data);
    else if (keysym == 119) // W
        move_forward(data);
    else if (keysym == 115) // S
        move_backward(data);
    else if (keysym == 97)  // A
        move_left(data);
    else if (keysym == 100) // D
        move_right(data);
    return (0);
}