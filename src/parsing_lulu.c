/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lulu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:23 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/29 11:48:19 by ldevigne         ###   ########.fr       */
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

int	get_safe_fd(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open file.\n", 1);
	return (fd);
}

bool	check_content(const char *map_path)
{
	/* need to implement checking for textures, colors etc. */
	if (!map_is_closed_by_walls(map_path))
		return (false);
	return (true);
}

bool	is_valid(const char *map_path)
{
	size_t		len_map;

	len_map = ft_strlen(map_path);
	if (!map_path)
		return (false);
	if (!extension_is_correct(map_path, len_map))
		return (false);
	if (get_safe_fd(map_path) == -1)
		return (false);
	else
		return (check_content(map_path));
	return (true);
}

int	get_x_len(const char *map_path)
{
	char	*line;
	int		fd;
	int		x;
	int		i;

	i = 0;
	x = 0;
	fd = get_safe_fd(map_path);
	while (i++ < 8)// on skip les 8 premieres lignes
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
			i++;
		if (i > x)
			x = i;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), x);
}

int	get_y_len(const char *map_path)
{
	char	*line;
	int		fd;
	int		y;
	

	y = -8;// need to return total lines in files BUT ignoring 8 first lines
	fd = get_safe_fd(map_path);
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (close(fd), y);
}

/*
int	**convert_file_to_map(const char *map)
{
	int		**tab;
	int		*data;
	int		x, y;
	int		x_len, y_len;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open map file\n", 1);

	x_len = get_x_len(map);
	y_len = get_y_len(map);

	tab = malloc(sizeof(int*) * y_len);
	if (!tab)
		ft_error_msg("Memory allocation failed (tab)\n", 1);

	data = malloc(sizeof(int) * x_len * y_len);
	if (!data)
	{
		free(tab);
		ft_error_msg("Memory allocation failed (data)\n", 1);
	}

	for (int i = 0; i < y_len; i++)
		tab[i] = data + (i * x_len);  // setup lignes

	for (y = 0; y < y_len; y++)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error_msg("Unexpected end of file\n", 1);

		for (x = 0; x < x_len && line[x] != '\n' && line[x] != '\0'; x++)
			tab[y][x] = line[x];  // convert '1' → 1, etc.

		free(line);
	}
	return (close(fd), tab);
}

char	**fill_map_struct(const char *map)
{
	char	**tab;
}

void	data_init_tab(t_tab *global_struct, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open map file\n", 1);
	global_struct->x_len = get_x_len(map_file);
	global_struct->y_len = get_y_len(map_file);
	global_struct->tab = fill_map_struct(map_file);
	close(fd);
}
*/

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

void	fill_grid(t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = get_safe_fd(map->map_path);
	line = NULL;
	map->grid = NULL;
	printf("x_len:%d | y_len:%d\n", map->x_len, map->y_len);
	map->grid = malloc(sizeof(char *) * (map->y_len + 1));
	if (!(map->grid))
	{
		ft_clear_map(map);
		ft_error_msg("Unable to malloc tab!\n", 1);
	}
	skip_lines(fd, line, 8);
	y = 0;
	while (y < map->y_len)
	{
		line = get_next_line(fd);
		if (!line)
			break;

		map->grid[y] = malloc(sizeof(char) * (map->x_len + 1)); // +1 pour \0
		if (!map->grid[y])
		{
			ft_clear_map(map);
			ft_error_msg("Unable to malloc line!\n", 1);
		}
		int x = 0;
		while (x < map->x_len && line[x] && line[x] != '\n')
		{
			map->grid[y][x] = line[x];
			x++;
		}
		map->grid[y][x] = '\0';
		free(line);
		y++;
	}
	map->grid[y] = '\0';
	close(fd);
}

int	get_color_from_string(char *str)
{
	return (ft_atoi(str));
}

void	get_textures(t_map *map)
{
	int		fd;
	char	*line;

	fd = get_safe_fd(map->map_path);
	line = get_next_line(fd);

	while (line)
	{
		if (!ft_strncmp(line, "NO ./", 3))
			map->north_texture = ft_strdup(line);
		else if (!ft_strncmp(line, "SO ./", 3))
			map->south_texture = ft_strdup(line);
		else if (!ft_strncmp(line, "WE ./", 3))
			map->west_texture = ft_strdup(line);
		else if (!ft_strncmp(line, "EA ./", 3))
			map->east_texture = ft_strdup(line);
		else if (!ft_strncmp(line, "F ", 1))
			map->floor_color = get_color_from_string(line + 2);
		else if (!ft_strncmp(line, "C ", 1))
			map->ceiling_color = get_color_from_string(line + 2);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

void	fill_map_struct(const char *map_path, t_map *map)
{
	map->map_path = ft_strdup(map_path);
	map->x_len = get_x_len(map_path);
	map->y_len = get_y_len(map_path);
	get_textures(map);
	fill_grid(map);
}

void	display_grid(char **grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			printf("tab[%d][%d]:%c | ", i, j, grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	display_map(t_map *map)
{
	if (map->map_path)
		printf("File name : %s\n", map->map_path);
	if (map->east_texture)
		printf("E: %s", map->east_texture);
	if (map->north_texture)
		printf("N: %s", map->north_texture);
	if (map->south_texture)
		printf("S: %s", map->south_texture);
	if (map->west_texture)
		printf("W: %s", map->west_texture);
	printf("Floor color : %d\n", map->floor_color);
	printf("Ceiling color : %d\n", map->ceiling_color);
	printf("Grid\n");
	display_grid(map->grid);
}
