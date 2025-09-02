/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_are_in_valid_format.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:31:39 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:36:01 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	textures_are_in_valid_format(char *texture)
{
	size_t	len_text;

	len_text = ft_strlen(texture);
	if (texture[len_text - 1] != 'm')
		return (false);
	if (texture[len_text - 2] != 'p')
		return (false);
	if (texture[len_text - 3] != 'x')
		return (false);
	if (texture[len_text - 4] != '.')
		return (false);
	return (true);
}
