/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:11:57 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/27 10:00:12 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	len_of_str;

	len_of_str = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		len_of_str++;
		str++;
	}
	return (len_of_str);
}
