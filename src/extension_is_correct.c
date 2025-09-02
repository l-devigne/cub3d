/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_is_correct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:46:00 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:46:24 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	extension_is_correct(const char *map_path, size_t len_map)
{
	if (map_path[len_map - 1] != 'b')
		return (false);
	if (map_path[len_map - 2] != 'u')
		return (false);
	if (map_path[len_map - 3] != 'c')
		return (false);
	if (map_path[len_map - 4] != '.')
		return (false);
	return (true);
}
