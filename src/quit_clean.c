/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:27 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/26 17:02:59 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clear_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// free_tab_of_tab(data->tab->tab);
	// free_tab_of_tab(data->tab->tab_color);
	// free(data->tab);
	// free(data);
}

int	click_cross(t_data *data)
{
	ft_clear_all(data);
	exit(0);
	return (0);
}

int	esc_key(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		ft_clear_all(data);
		exit(0);
	}
	return (0);
}