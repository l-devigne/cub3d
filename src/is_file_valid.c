/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:46:43 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:47:00 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_file_valid(const char *map_path)
{
	size_t	len_map;

	len_map = ft_strlen(map_path);
	if (!map_path)
		return (false);
	if (!extension_is_correct(map_path, len_map))
		return (false);
	if (get_safe_fd(map_path, CLOSE) == -1)
		return (false);
	if (!no_walls_alone(map_path))
		return (false);
	return (true);
}
