/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_without_eol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:07:27 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 22:07:38 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_str_without_eol(char *s, t_data *data)
{
	int		size_to_dup;
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	size_to_dup = 0;
	while (s[size_to_dup] && s[size_to_dup] != '\n')
		size_to_dup++;
	copy = malloc(sizeof(char) * (size_to_dup + 1));
	if (!copy)
	{
		ft_clear_all(data, 1);
		return (NULL);
	}
	i = 0;
	while (i < size_to_dup)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
