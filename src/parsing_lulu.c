/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lulu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:23 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/28 15:31:12 by ldevigne         ###   ########.fr       */
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

/* parsing a proprement parler */

int	get_x_len(const char *map)
{
	char	*line;
	int		fd;
	int		x;
	int		i;

	i = 0;
	x = 0;
	fd = open(map, O_RDONLY);
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
	return (free(line), close(fd), x);
}

int	get_y_len(const char *map)
{
	char	*line;
	int		fd;
	int		y;
	
	y = -8;// need to return total lines in files BUT ignoring 8 first lines
	fd = open(map, O_RDONLY);
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

// int	**convert_file_to_map(const char *map)
// {
// 	int		**tab;
// 	int		*data;
// 	int		x, y;
// 	int		x_len, y_len;
// 	int		fd;
// 	char	*line;

// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		ft_error_msg("Unable to open map file\n", 1);

// 	x_len = get_x_len(map);
// 	y_len = get_y_len(map);

// 	tab = malloc(sizeof(int*) * y_len);
// 	if (!tab)
// 		ft_error_msg("Memory allocation failed (tab)\n", 1);

// 	data = malloc(sizeof(int) * x_len * y_len);
// 	if (!data)
// 	{
// 		free(tab);
// 		ft_error_msg("Memory allocation failed (data)\n", 1);
// 	}

// 	for (int i = 0; i < y_len; i++)
// 		tab[i] = data + (i * x_len);  // setup lignes

// 	for (y = 0; y < y_len; y++)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			ft_error_msg("Unexpected end of file\n", 1);

// 		for (x = 0; x < x_len && line[x] != '\n' && line[x] != '\0'; x++)
// 			tab[y][x] = line[x];  // convert '1' → 1, etc.

// 		free(line);
// 	}
// 	return (close(fd), tab);
// }



// char	**convert_file_to_tab(const char *map)
// {
// 	char	**tab;
// }

// void	data_init_tab(t_tab *global_struct, char *map_file)
// {
// 	int	fd;

// 	fd = open(map_file, O_RDONLY);
// 	if (fd < 0)
// 		ft_error_msg("Unable to open map file\n", 1);
// 	global_struct->x_len = get_x_len(map_file);
// 	global_struct->y_len = get_y_len(map_file);
// 	global_struct->tab = convert_file_to_tab(map_file);
// 	close(fd);
// }

char	**convert_file_to_tab(const char *map)
{
	// t_tab	*new_tab;
	char	**tab = NULL;
	int		x_len;
	int		y_len;
	int		fd;
	char	*line;
	int		y;

	// data_init_tab(new_tab, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open map file\n", 1);

	// Récupération des dimensions
	x_len = get_x_len(map);
	y_len = get_y_len(map);

	tab = malloc(sizeof(char *) * (y_len + 1)); // +1 pour NULL-termination éventuelle
	if (!tab)
		ft_error_msg("Unable to malloc tab!\n", 1);

	printf("x_len:%d | y_len:%d\n", x_len, y_len);

	// Skip les 8 premières lignes
	for (int i = 0; i < 8; i++)
	{
		line = get_next_line(fd);
		free(line);
	}

	y = 0;
	while (y < y_len)
	{
		line = get_next_line(fd);
		if (!line)
			break;

		tab[y] = malloc(sizeof(char) * (x_len + 1)); // +1 pour \0
		if (!tab[y])
			ft_error_msg("Unable to malloc line!\n", 1);

		int x = 0;
		while (x < x_len && line[x] && line[x] != '\n')
		{
			tab[y][x] = line[x];
			x++;
		}
		tab[y][x] = '\0';
		free(line);
		y++;
	}
	tab[y] = '\0';
	return (close(fd), tab);
}
