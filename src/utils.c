/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:11:57 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/27 12:48:34 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
