/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:35:26 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:41:53 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_left(t_map *map, int i, int j)
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
			break ;
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

int	check_right(t_map *map, int i, int j)
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
			break ;
		}
		else
			j++;
		if (j > (int)ft_strlen(map->grid[i]))
			return (-1);
	}
	if (right == false)
		return (-1);
	return (tmp);
}

int	check_up(t_map *map, int i, int j)
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
			break ;
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

int	check_down(t_map *map, int i, int j)
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
			break ;
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
