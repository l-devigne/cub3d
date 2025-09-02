/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:46:07 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/02 13:31:13 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_test(t_map *test)
{
	char	*grid_linear;

	grid_linear = "111111\n100101\n101001\n1100S1\n111111";
	test->grid = ft_split(grid_linear, '\n');
	test->ceiling_color = 0xFFFFFF;
	test->floor_color = 0x000000FF;
	test->south_texture = "textures/SO.xpm";
	test->north_texture = "textures/NO.xpm";
	test->west_texture = "textures/WE.xpm";
	test->east_texture = "textures/EA.xpm";
}

void	init_player(char **grid, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != '0' && grid[i][j] != '1' && grid[i][j] != ' ')
			{
				player->x = ((float)j + ((float)j + 1)) / 2;
				player->y = ((float)i + ((float)i + 1)) / 2;
				break ;
			}
			++j;
		}
		if (grid[i][j] != '\0' && grid[i][j] != '0' && grid[i][j] != '1')
			break ;
		++i;
	}
	if (grid[i][j] == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66; // 2D camera plane (FOV control)
		player->plane_y = 0;
	}
	else if (grid[i][j] == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (grid[i][j] == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

void	print_map(t_map map)
{
	int	i;

	i = 0;
	printf("#####MAP######\n\n");
	while (map.grid[i])
	{
		printf("{%d}__%s\n", i, map.grid[i]);
		++i;
	}
	printf("\n#####TEXTURES######\n");
	printf("\npath to SO texture is : %s\n", map.south_texture);
	printf("path to NO texture is : %s\n", map.north_texture);
	printf("path to WE texture is : %s\n", map.west_texture);
	printf("path to EA texture is : %s\n", map.east_texture);
	printf("\n#####COLORS######\n");
	printf("\ncolor of the ceiling is : %d\n", map.ceiling_color);
	printf("color of the ceiling is : %d\n", map.floor_color);
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

int	main(int ac, char **av)
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_texture	texture;
	t_keys		keys;

	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
	texture.tex_img = NULL;
	ft_memset(&map, 0, sizeof(map));
	// very important to set all data to null pointers before loading them
	// init_test(&test_map);
	if (!is_file_valid(av[1])) // check the file (extension, fd etc)
		return (ft_error_msg("Error with map file\n", 1), 1);
	fill_map_struct(av[1], &map); // load the map with the file
	/* map is loaded -> need to check content of it */
	if (!check_map(&map))
		return (ft_clear_map(&map, 0), 1);
	/* END OF PARSING */
	init_player(map.grid, &player);
	// print_map(map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1700, 1000, "CUB3D");
	data.img = initialize_image(data.mlx, 1500, 800);
	data.player = &player;
	data.map = &map;
	data.text = &texture;
	init_keys(&data, &keys);
	data.screen_height = 800;
	data.screen_width = 1500;
	draw_whole_screen(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 50, 50);
	mlx_hook(data.win, 17, 0, &click_cross, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, detect_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, detect_key_release, &data);
	mlx_loop_hook(data.mlx, handle_keys, &data);
	mlx_loop(data.mlx);
	return (0);
}
