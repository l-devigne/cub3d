/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:27 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/02 11:48:43 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	char_free_null(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

void	tab_free_null(char ***tab)
{
	int	i;

	i = 0;
	if (!*tab)
		return ;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	ft_clear_map(t_map *map, int error_code)
{
	char_free_null(&map->north_texture);
	char_free_null(&map->south_texture);
	char_free_null(&map->west_texture);
	char_free_null(&map->east_texture);
	char_free_null(&map->map_path);
	tab_free_null(&map->grid);
	if (error_code == 1)
		ft_error_msg("Error!\n", 1);
}

void	ft_clear_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_image(data->mlx, data->text->tex_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_clear_map(data->map, 0);
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
void	close_window(t_data *data)
{
	ft_clear_all(data);
	exit(0);
}