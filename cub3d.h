/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:49:17 by ldevigne          #+#    #+#             */
/*   Updated: 2025/08/27 11:57:50 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct string
{
	char	*first;
	char	*last;
}	t_STRING;

char			*ft_nl(void);
char			*ft_line(int fd, char *reponse);
char			*get_next_line(int fd);
int				ft_get_index(char *buffer, char sep);
char			*ft_copy(char *source, int start, int end);
struct	string	*ft_cut(char *source);
char			*ft_join(char *s1, char *s2, int flag);
void			ft_free(void *s);
char			*ft_free_and_return_null(char *s1, char *s2, int flag);
struct string	*malloc_and_check(struct string *reponse, int nb_bytes);

void			ft_error_msg(char *msg, int exit_code);
bool			is_valid(const char *map);
bool			extension_is_correct(const char *map_file, size_t len_map);
size_t			ft_strlen(const char *str);

bool			is_map_square(const char *pathname);
bool			only_valid_chars(const char *pathname);