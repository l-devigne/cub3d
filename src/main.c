/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:46:07 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/02 22:04:15 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_and_hook(t_data *data)
{
	draw_whole_screen(data);
	mlx_hook(data->win, 17, 0, &click_cross, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, detect_key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, detect_key_release, data);
	mlx_loop_hook(data->mlx, handle_keys, data);
	mlx_loop(data->mlx);
}

void	init_window_image(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data->mlx), exit(1));
	data->win = mlx_new_window(data->mlx, 1700, 1000, "CUB3D");
	if (!data->win)
		return (mlx_destroy_display(data->mlx), free(data->mlx), exit(1));
	data->img = initialize_image(data->mlx, 1700, 1000);
	data->screen_height = 1000;
	data->screen_width = 1700;
}

int	main(int ac, char **av)
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_texture	texture;
	t_keys		keys;

	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
	if (!is_file_valid(av[1]))
		return (ft_error_msg("Error with map file\n", 1), 1);
	init_data_null(&data);
	texture.tex_img = NULL;
	init_window_image(&data);
	data.map = &map;
	fill_map_struct(&data, av[1], &map);
	if (!check_map(&map))
		return (ft_clear_all(&data, 0), 1);
	init_player(&data, map.grid, &player);
	data.text = &texture;
	init_keys(&data, &keys);
	draw_and_hook(&data);
	return (0);
}
