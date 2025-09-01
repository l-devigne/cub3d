/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lulu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:21 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/01 10:09:14 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	char_free_null(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

void	tab_free_null(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_clear_map(t_map *map, int error_code)
{
	char_free_null(&map->north_texture);
	char_free_null(&map->south_texture);
	char_free_null(&map->west_texture);
	char_free_null(&map->east_texture);
	char_free_null(&map->map_path);
	tab_free_null(map->grid);
	free(map);
	if (error_code == 1)
		ft_error_msg("Error!\n", 1);
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;//struct to parse from map_path file
	
// 	map = NULL;
// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		ft_error_msg("Malloc failed.\n", 1);
// 	ft_memset(map, 0, sizeof(t_map));// pour init tous les ptrs de la struct a NULL
// 	if (ac != 2)
// 		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
// 	if (!is_valid(av[1]))// goes to global function tester
// 		return (ft_error_msg("Error with map file\n", 1), 1);
// 	/* Entry file is correct - let's do the parsing then verify walls etc */
// 	fill_map_struct(av[1], map);
// 	if (!map_is_closed_by_walls(map))
// 		return (ft_clear_map(map, 1), 1);
// 	printf("Welcome in cub3d\n");
// 	display_map(map);
// 	ft_clear_map(map, 0);
// }
