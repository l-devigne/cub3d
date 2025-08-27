/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:36 by aherlaud          #+#    #+#             */
/*   Updated: 2025/08/26 17:08:54 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	initialize_image(void *mlx, int width, int height)
{
	t_img	img;

	img.mlx_img = mlx_new_image(mlx, width, height);
	if (!(img.mlx_img))
		return (img);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,
			&img.endian);
	img.width = width;
	img.height = height;
	return (img);
}