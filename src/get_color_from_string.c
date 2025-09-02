/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:08:15 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:08:28 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	int		r;
	int		g;
	int		b;
	char	*ptr;

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
	r = set_color_limit(r);
	g = set_color_limit(g);
	b = set_color_limit(b);
	return ((r << 16) | (g << 8) | b);
}
