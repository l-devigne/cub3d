/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:46:07 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/27 18:57:01 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_test(t_map *test)
{
    char *grid_linear = "111111\n100101\n101001\n1100N1\n111111";

    test->grid = ft_split(grid_linear, '\n'); 
    test->ceiling_color = 0x00FF0000;
    test->floor_color = 0x000000FF;
    test->south_texture = "textures/SO.xpm";
    test->north_texture = "textures/NO.xpm";
    test->west_texture = "textures/WE.xpm";
    test->east_texture = "textures/EA.xpm";
}



void init_player(char **grid, t_player *player)
{
    int i;
    int j;

    i = 0;
    while(grid[i])
    {
        j = 0;
        while(grid[i][j])
        {
            if(grid[i][j] != '0' && grid[i][j] != '1')
            {
                player->x = ((float)j + ((float)j + 1)) / 2;
                player->y= ((float)i + ((float)i + 1)) / 2;
                break;         
            }
        }
    }
    
    if (grid[i][j] == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1;
        player->plane_x = 0.66;  // 2D camera plane (FOV control)
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

void print_map(t_map map)
{
    int i;

    i = 0;
    
    printf("#####MAP######\n\n");
    while(map.grid[i])
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

int	main(void)
{
    t_data data;
    t_map  test_map;
    t_player  player;

    init_test(&test_map);
    init_player(test_map.grid, &player);
    print_map(test_map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1900, 1000, "CUB3D");
    data.img = initialize_image(data.mlx, 1700, 800);


    mlx_hook(data.win, 17, 0, &click_cross, &data);
	mlx_key_hook(data.win, &esc_key, &data);
    mlx_loop(data.mlx);
	return (0);
}