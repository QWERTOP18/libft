/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:49:14 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/14 13:19:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ENDIAN 8
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef DEBUG
#  include <stdio.h>
#  include <string.h>
# endif

// # define _ISBIT(bit) ((bit < 8) ? (1 << (bit)) << 8 : (1 << (bit)) >> 8)
/* ************************************************************************** */
/*                                STDLIB                                      */
/* ************************************************************************** */
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                                 CTYPE                                      */
/* ************************************************************************** */

typedef enum e_ctype
{
	_ISUPPER = 1 << (0 + ENDIAN),
	_ISLOWER = 1 << (1 + ENDIAN),
	_ISALPHA = 1 << (2 + ENDIAN),
	_ISDIGIT = 1 << (3 + ENDIAN),
	_ISXDIGIT = 1 << (4 + ENDIAN),
	_ISSPACE = 1 << (5 + ENDIAN),
	_ISPRINT = 1 << (6 + ENDIAN),
	_ISGRAPH = 1 << (7 + ENDIAN),
	_ISBLANK = 1 << (8),
	_ISCNTRL = 1 << (9),
	_ISPUNCT = 1 << (10),
	_ISALNUM = 1 << (11)
}					t_ctype;

void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/* ************************************************************************** */
/*                                 STRINGS                                    */
/* ************************************************************************** */
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_strs_free(char **tab);

/* ************************************************************************** */
/*                                 STREAM                                     */
/* ************************************************************************** */
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/*                                 LIST                                       */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **list, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
size_t				ft_lstsize(t_list *lst);

#endif // LIBFT_H