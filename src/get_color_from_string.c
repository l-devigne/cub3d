/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:08:15 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/07 19:36:48 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	rgb_is_ok(char *color, int i)
{
	int	count;

	count = 0;
	if (color[i] == '-')
		return (false);
	while (color[i] && color[i] != ',')
	{
		if (color[i] >= '0' && color[i] <= '9')
			count++;
		i++;
	}
	if (count > 3)
		return (false);
	return (true);
}

bool	str_countains_valid_nb_coma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == ',')
		return (false);
	while (str[i])
	{
		if (!rgb_is_ok(str, i))
			return (false);
		if (str[i] == ',')
		{
			count++;
			if (!rgb_is_ok(str, i + 1))
				return (false);
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (false);
		}
		i++;
	}
	if (count != 2)
		return (false);
	return (true);
}

bool	check_rgb(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		return (false);
	if (r < 0 || g < 0 || b < 0)
		return (false);
	return (true);
}

int	get_color_from_string(char *str)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	if (!str_countains_valid_nb_coma(str))
		return (-1);
	r = ft_atoi(str);
	ptr = str;
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
	if (!check_rgb(r, g, b))
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
