/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:27 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/03 14:39:46 by ldevigne         ###   ########.fr       */
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
	if (map->north_texture)
		char_free_null(&map->north_texture);
	if (map->south_texture)
		char_free_null(&map->south_texture);
	if (map->west_texture)
		char_free_null(&map->west_texture);
	if (map->east_texture)
		char_free_null(&map->east_texture);
	if (map->map_path)
		char_free_null(&map->map_path);
	if (map->grid)
		tab_free_null(&map->grid);
	if (error_code == 1)
		ft_error_msg("Error!\n", 1);
}

void	ft_clear_all(t_data *data, int error_code)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->text && data->text->tex_img)
		mlx_destroy_image(data->mlx, data->text->tex_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->map)
		ft_clear_map(data->map, error_code);
}
