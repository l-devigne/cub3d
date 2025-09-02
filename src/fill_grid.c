/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:09:08 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:09:55 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	skip_lines(int fd, char *line, int nb_to_skip)
{
	int	i;

	i = 0;
	while (i < nb_to_skip)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
}

void	fill_single_line(t_map *map, char *line, int y)
{
	int	x;

	map->grid[y] = malloc(sizeof(char) * (map->x_len + 1));
	if (!map->grid[y])
		ft_clear_map(map, 1);
	x = 0;
	while (x < map->x_len && line[x] && line[x] != '\n')
	{
		map->grid[y][x] = line[x];
		x++;
	}
	map->grid[y][x] = '\0';
}

void	fill_grid(t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = get_safe_fd(map->map_path, KEEP_OPEN);
	line = NULL;
	map->grid = NULL;
	map->grid = malloc(sizeof(char *) * (map->y_len + 1));
	if (!(map->grid))
		ft_clear_map(map, 1);
	skip_lines(fd, line, map->num_of_lines_to_skip);
	y = 0;
	while (y < map->y_len)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_single_line(map, line, y);
		free(line);
		y++;
	}
	map->grid[y] = NULL;
	close(fd);
}
