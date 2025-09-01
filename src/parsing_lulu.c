/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lulu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:23 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/01 10:43:51 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_x_len(const char *map_path)
{
	char	*line;
	int		fd;
	int		x;
	int		i;
	int		nb_to_skip;

	x = 0;
	nb_to_skip = get_lines_num_to_skip(map_path);
	fd = get_safe_fd(map_path, KEEP_OPEN);
	while (nb_to_skip-- > 0)
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
	

	y = 0;
	fd = get_safe_fd(map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	y -= get_lines_num_to_skip(map_path);
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

void	fill_single_line(t_map *map, char *line, int y)
{
	int	x;


	map->grid[y] = malloc(sizeof(char) * (map->x_len + 1)); // +1 pour \0
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
	printf("x_len:%d | y_len:%d\n", map->x_len, map->y_len);
	map->grid = malloc(sizeof(char *) * (map->y_len + 1));
	if (!(map->grid))
		ft_clear_map(map, 1);
	skip_lines(fd, line, map->num_of_lines_to_skip);
	y = 0;
	while (y < map->y_len)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		fill_single_line(map, line, y);
		free(line);
		y++;
	}
	map->grid[y] = '\0';
	close(fd);
}

int		ft_strtol(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else
			break ;
		i++;
	}
    return (result);
}

int	set_color_limit(int val)
{
	if (val < 0)
		val = 0;
	if (val > 255)
		val = 255;
	return (val);
}

int	get_color_from_string(char *str)
{
	int 	r;
	int		g;
	int		b;
	char	*ptr;

	r = 0;
	g = 0;
	b = 0;
	str = ft_itoa(ft_strtol(str));
	ptr = str;
	r = ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	g = ft_atoi(ptr);
	while (*ptr && *ptr != ',')
		ptr++;
	if (*ptr == ',')
		ptr++;
	b = ft_atoi(ptr);
	r = set_color_limit(r);
	g = set_color_limit(g);
	b = set_color_limit(b);
	return (free(str), (r << 16) | (g << 8) | b);// need to free (str) cause malloc inside itoa
}

void	get_textures(t_map *map)
{
	int		fd;
	char	*line;

	fd = get_safe_fd(map->map_path, KEEP_OPEN);
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

int		get_lines_num_to_skip(const char *map_path)
{
	int			fd;
	char		*line;
	int			line_count;

	line_count = 0;
	fd = get_safe_fd(map_path, KEEP_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		{
			free(line);
			line = get_next_line(fd);
			line_count++;
		}
		else if (!ft_strcmp(line, "\n") || !ft_strncmp(line, "F ", 2)
				|| !ft_strncmp(line, "C ", 2))
		{
			free(line);
			line = get_next_line(fd);
			line_count++;
		}
		else
			break;
	}
	return (free(line), close(fd), (line_count));
}

void	fill_map_struct(const char *map_path, t_map *map)
{
	map->map_path = ft_strdup(map_path);
	map->num_of_lines_to_skip = get_lines_num_to_skip(map_path);
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
	printf("Grid starts at line %d\n", map->num_of_lines_to_skip);
	display_grid(map->grid);
}
