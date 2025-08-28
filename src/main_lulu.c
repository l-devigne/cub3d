/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lulu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:21 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/28 14:32:40 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error_msg(char *msg, int exit_code)
{
	printf("%s", msg);
	exit(exit_code);
}

void	display_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i][j])
	{
		printf("%c", tab[i][j]);
		j++;
	}
}

/* test depuis ma branche (lulu) */
int	main(int ac, char **av)
{
	char	**tab;
	
	if (ac != 2)
		return (ft_error_msg("Wrong number of arguments\n", 1), 1);
	if (!is_valid(av[1]))
		return (ft_error_msg("Error with map file\n", 1), 1);
	printf("Welcome in cub3d\n");
	tab = convert_file_to_tab(av[1]);
	printf("RAS\n");
	display_tab(tab);
}
