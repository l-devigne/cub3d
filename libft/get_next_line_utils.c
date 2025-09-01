/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:58:39 by lflayeux          #+#    #+#             */
/*   Updated: 2025/06/14 00:42:02 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// flag can free what you want
// 0 = no free
// 2 = free of s1
// 1 = free of s2
// 3 = free both s1 and s2
char	*ft_free_and_return_null(char *s1, char *s2, int flag)
{
	if (s1 && (flag & 2))
		ft_free (s1);
	if (s2 && (flag & 1))
		ft_free (s2);
	return (NULL);
}

void	ft_free(void *s)
{
	if (s)
		free(s);
}

// result is s1+s2
// pay attention about flag
// flag can free or not free s1 and/or s2 (usecase of "\n")
char	*ft_join(char *s1, char *s2, int flag)
{
	char	*new_str;
	int		l;
	int		i;
	int		j;

	l = 0;
	i = 0;
	j = 0;
	new_str = NULL;
	l = ft_get_index(s1, 0) + 1 + ft_get_index(s2, 0) + 1;
	if (l > 0)
	{
		new_str = (char *) malloc(l + 1);
		if (!new_str)
			return (ft_free_and_return_null(s1, s2, flag), NULL);
		if (s1 != NULL)
			while (s1[i])
				new_str[j++] = s1[i++];
		i = 0;
		if (s2 != NULL)
			while (s2[i])
				new_str[j++] = s2[i++];
		new_str[j] = '\0';
	}
	return (ft_free_and_return_null(s1, s2, flag), new_str);
}

// if not found or NULL, result is -1
// else result is indice of first occurence of char sep
// notice : sep='\0' can be used like a regular strlen (used in join)
int	ft_get_index(char *buffer, char sep)
{
	int		i;

	i = 0;
	if (buffer == NULL)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == sep)
			return (i);
		i++;
	}
	if (i != 0 && sep == 0)
		return (i - 1);
	return (-1);
}

// copy fragment of source between start and end (including)
// if start = end, return a char * with one char
char	*ft_copy(char *source, int start, int end)
{
	int		i;
	char	*reponse;

	i = 0;
	if (end < start)
		return (NULL);
	reponse = malloc (end - start + 2);
	if (!reponse)
		return (NULL);
	while (source[start + i] && (start + i) <= end)
	{
		reponse[i] = source[start + i];
		i++;
	}
	reponse[i] = '\0';
	return (reponse);
}