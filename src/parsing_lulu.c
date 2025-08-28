/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lulu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:23 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/28 12:06:52 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	extension_is_correct(const char *map_file, size_t len_map)
{
	if (map_file[len_map - 1] != 'b')
		return (false);
	if (map_file[len_map - 2] != 'u')
		return (false);
	if (map_file[len_map - 3] != 'c')
		return (false);
	if (map_file[len_map - 4] != '.')
		return (false);
	return (true);
}

int	file_is_openable(const char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	return (fd);
}

bool	check_content(const char *pathname)
{
	if (!map_is_closed_by_walls(pathname))
		return (false);
	return (true);
}

bool	is_valid(const char *map)
{
	size_t		len_map;
	int			fd;

	len_map = ft_strlen(map);
	if (!map)
		return (false);
	if (!extension_is_correct(map, len_map))
		return (false);
	fd = file_is_openable(map);
	if (fd == -1)
		return (false);
	else
		return (check_content(map));
	return (true);
}
