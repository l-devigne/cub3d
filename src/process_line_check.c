/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:42:13 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:42:29 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	process_line_check(const char *line)
{
	size_t	len_line;
	size_t	i;

	if (!line)
		return (false);
	i = 0;
	len_line = ft_strlen(line);
	while (line && *line)
	{
		if (*line == '1' || *line == ' ')
			line++;
		else if (*line == '\n')
		{
			i++;
			break ;
		}
		else
			break ;
		i++;
	}
	if (i == len_line)
		return (true);
	return (false);
}
