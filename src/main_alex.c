/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:46:07 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/26 17:09:35 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
    t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1900, 1000, "CUB3D");
    data.img = initialize_image(data.mlx, 1700, 800);

    
    mlx_hook(data.win, 17, 0, &click_cross, &data);
	mlx_key_hook(data.win, &esc_key, &data);
    mlx_loop(data.mlx);
	return (0);
}