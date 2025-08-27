/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lulu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:21 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/27 12:48:24 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error_msg(char *msg, int exit_code)
{
	printf("%s", msg);
	exit(exit_code);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
	if (!is_valid(av[1]))
		return (ft_error_msg("Error with map file\n", 1), 1);
	printf("Welcome in cub3d\n");
}
