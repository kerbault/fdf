/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:45:12 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 19:32:33 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Include headers for the typedefs, macros and standard functions
** stdlib.h for the functions malloc and free
** string.h for the macro NULL and the typedef size_t
** unistd.h for the function write
*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>

# define NULL_CHECK(x) if (x == NULL) return (NULL)
# define VOID_NULL_CHECK(x) if (x == NULL) return
# define MALLOC_CHECK(x) if (x == NULL) return (NULL)

/*
** Struct for a linked list
** \member content The data contained inside the link
** \member content_size The size of the data contained in the link
** \member next The adress of the next link or NULL if it's the last
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Typedef for the memory related functions
*/
typedef unsigned char	t_byte;

/*
** Functions already existing in the libc, rewrited for this library
** see man function (without the ft_)
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);

/*
** Functions missing from the libc or present in a different way
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(const int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, const int fd);
void				ft_putendl_fd(const char *s, const int fd);
void				ft_putnbr_fd(int n, const int fd);

/*
** Functions to manipulate a linked list
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Useful additional functions
*/
void				ft_putaddr(void *ptr);
void				ft_putaddr_fd(void *ptr, int fd);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
void				ft_swap(void *s1, void *s2);
char				*ft_itoa_base(int value, int base);
size_t				ft_putwchar_fd(wchar_t wc, const int fd);
size_t				ft_putwchar(wchar_t wc);
void				ft_putwstr_fd(wchar_t *s, const int fd);
void				ft_putwstr(wchar_t *s);

#endif
