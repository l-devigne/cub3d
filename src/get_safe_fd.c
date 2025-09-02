/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:45:36 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/02 21:45:50 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_safe_fd(const char *map_path, int flag)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Unable to open file.\n", 1);
	if (flag == CLOSE)
		close(fd);
	return (fd);
}
