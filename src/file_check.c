/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:38:04 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/31 19:48:59 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_valid(const char *map_path)
{
	size_t		len_map;

	len_map = ft_strlen(map_path);
	if (!map_path)
		return (false);
	if (!extension_is_correct(map_path, len_map))
		return (false);
	if (get_safe_fd(map_path, CLOSE) == -1)
		return (false);
	// if (!no_walls_alone(map_path))
	// 	return (false);
	// else
	// 	return (check_content(map_path));// we check that later after parsing
	return (true);
}

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

int	get_safe_fd(const char *map_path, int flag)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open file.\n", 1);
	if (flag == CLOSE)
		close(fd);
	return (fd);
}

// bool	check_content(const char *map_path)
// {
// 	/* need to implement CHECKING for textures, colors etc. */
// 	if (!map_is_closed_by_walls(map_path))
// 		return (false);
// 	return (true);
// }

bool	no_walls_alone(const char *map_path)
{
	int		start;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	start = get_lines_num_to_skip(map_path);
	while (start-- > 0)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	printf("no_walls_alone 1st line : [%s]\n", line);
	while (line)
	{
		if (!ft_strcmp(line, "\n"))
			return (close(fd), free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}

bool	process_line_check(const char *line)
{
	size_t	len_line;
	size_t	i;

	if (!line)
		return (false);
	i = 0;
	len_line = ft_strlen(line);
	while (line && *line)
	{
		if (*line == '1' || *line == ' ')
			line++;
		else if (*line == '\n')
		{
			i++;
			break;
		}
		else
			break;
		i++;
	}
	if (i == len_line)
		return (true);
	return (false);
}

bool	is_line_full_wall(char *line)
{
	if (!line)
		return (false);
	if (!process_line_check(line))
		return (false);
	return (true);
}

/* map->grid has been parsed, we need to do 2 steps 
1 - transform SPACE char to '1' (walls) 
2 - check if map is closed by walls */

int		check_left(t_map *map, int i, int j)
{
	bool	left;
	int		tmp;

	left = false;
	tmp = j;
	while (map->grid[i][j])
	{
		if (map->grid[i][j] == '1')
		{
			left = true;
			break;
		}
		else
			j--;
		if (j < 0)
			return (-1);
	}
	if (left == false)
		return (-1);
	return (tmp);

}
int		check_right(t_map *map, int i, int j)
{
	bool	right;
	int		tmp;

	right = false;
	tmp = j;
	while (map->grid[i][j])
	{
		if (map->grid[i][j] == '1')
		{
			right = true;
			break;
		}
		else
			j++;
		if (j > (int) ft_strlen(map->grid[i]))
			return (-1);
	}
	if (right == false)
		return (-1);
	return (tmp);
}

int		check_up(t_map *map, int i, int j)
{
	bool	up;
	int		tmp;

	up = false;
	tmp = j;
	while (map->grid[i][j])
	{
		if (map->grid[i][j] == '1')
		{
			up = true;
			break;
		}
		else
			i--;
		if (i < 0)
			return (-1);
	}
	if (up == false)
		return (-1);
	return (tmp);
}

int		check_down(t_map *map, int i, int j)
{
	bool	down;
	int		tmp;

	down = false;
	tmp = j;
	while (map->grid[i][j])
	{
		if (map->grid[i][j] == '1')
		{
			down = true;
			break;
		}
		else
			i++;
		if (i > map->y_len - 1)
			return (-1);
	}
	if (down == false)
		return (-1);
	return (tmp);
}

bool	map_is_closed_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '0')
			{
				if (check_left(map, i, j) == -1)
					return (false);
				if (check_right(map, i, j) == -1)
					return (false);
				if (check_up(map, i, j) == -1)
					return (false);
				if (check_down(map, i, j) == -1)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
