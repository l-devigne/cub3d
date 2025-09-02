/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lulu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:21 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 11:49:54 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



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
// 	if (!is_file_valid(av[1]))// goes to global function tester
// 		return (ft_error_msg("Error with map file\n", 1), 1);
// 	/* Entry file is correct - let's do the parsing then verify walls etc */
// 	fill_map_struct(av[1], map);
// 	if (!map_is_closed_by_walls(map))
// 		return (ft_clear_map(map, 1), 1);
// 	printf("Welcome in cub3d\n");
// 	display_map(map);
// 	ft_clear_map(map, 0);
// }
