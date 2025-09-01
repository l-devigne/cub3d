/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflayeux <lflayeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:28:20 by lflayeux          #+#    #+#             */
/*   Updated: 2025/06/16 18:10:21 by lflayeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//LIBFT

void	*ft_memcpy(void *dest, const void *src, size_t n);

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa(int n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	**ft_split(char const *s, char c);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t	ft_strlcat(char *dst, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t len);

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char*big, const char *little, size_t len);

char	*ft_strrchr(const char *str, int c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

void	*ft_calloc(size_t nb, size_t size);

int		ft_strcmp(const char *s1, const char *s2);

void	ft_free_tab(void **tab);

int		ft_intlen(int nb);

char	*ft_realloc(char *ptr, size_t size);

// GET_NEXT_LINE

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

// FT_PRINTF

int		ft_putnbrhexa(unsigned long int nb);
int		ft_putnbrhexa_up(unsigned long int nb);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long int nb);
int		ft_printf(const char *format, ...);

#endif
