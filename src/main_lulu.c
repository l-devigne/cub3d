/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lulu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:21 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/29 11:10:40 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error_msg(char *msg, int exit_code)
{
	printf("%s", msg);
	exit(exit_code);
}

void	char_free_null(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
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

void	ft_clear_map(t_map *map)
{
	char_free_null(map->map_path);
	char_free_null(map->east_texture);
	char_free_null(map->west_texture);
	char_free_null(map->north_texture);
	char_free_null(map->south_texture);
	tab_free_null(map->grid);
}

int	main(int ac, char **av)
{
	t_map	*map;//struct to parse from map_path file
	
	map = NULL;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error_msg("Malloc failed.\n", 1);
	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
	if (!is_valid(av[1]))// goes to global function tester
		return (ft_error_msg("Error with map file\n", 1), 1);
	/* Entry file is correct - let's do the parsing */
	printf("Welcome in cub3d\n");
	fill_map_struct(av[1], map);
	display_map(map);
}
