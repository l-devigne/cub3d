/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:05:49 by lflayeux          #+#    #+#             */
/*   Updated: 2025/06/14 00:42:25 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// fonction to complete static char* from get_next_line using fd until nl/eof
char	*ft_line(int fd, char *reponse)
{
	int		read_bytes;
	char	*buffer;
	char	*retour;

	retour = ft_join(reponse, NULL, 3);
	while (ft_get_index(retour, '\n') == -1)
	{
		buffer = malloc (BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (ft_free(retour), NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free(buffer), ft_free(retour), NULL);
		if (read_bytes == 0)
			return (ft_free(buffer), retour);
		buffer[read_bytes] = '\0';
		retour = ft_join(retour, buffer, 3);
		if (!retour)
			return (NULL);
	}
	return (retour);
}

// cut source into 1 str before the first \n and the rest
struct	string	*ft_cut(char *source)
{
	struct string	*reponse;
	int				i;
	int				j;

	reponse = malloc (1 * sizeof(struct string));
	if (reponse == NULL)
		return (NULL);
	reponse->last = NULL;
	i = ft_get_index(source, '\n');
	if (i != -1)
	{
		reponse->first = ft_copy(source, 0, (i - 1));
		j = ft_get_index(source, '\0');
		reponse->last = ft_copy(source, i + 1, j);
		if (reponse->last == NULL)
		{
			reponse->last = (char *) malloc (1);
			if (reponse->last == NULL)
				return (ft_free(reponse->first), NULL);
			reponse->last[0] = '\0';
		}
	}
	else
		reponse->first = ft_join(source, NULL, 3);
	return (reponse);
}

// main function
char	*get_next_line(int fd)
{
	char			*copy_first;
	static char		*new_string;
	struct string	*tab;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (ft_free(new_string), NULL);
	new_string = ft_line(fd, new_string);
	if (new_string == NULL)
		return (NULL);
	tab = ft_cut(new_string);
	if (tab == NULL)
		return (NULL);
	if (tab->last != NULL)
		ft_free(new_string);
	new_string = tab->last;
	copy_first = tab->first;
	ft_free(tab);
	if (copy_first == NULL && new_string == NULL)
		return (NULL);
	if (copy_first == NULL)
		return (ft_join("\n", NULL, 0));
	if (new_string != NULL)
		return (ft_join(copy_first, "\n", 2));
	else
		return (ft_join(copy_first, NULL, 3));
}