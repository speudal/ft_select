/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:28:15 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 13:37:53 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1664
# define SIZE 2147483648

# include <string.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	char			wrong;
	char			conv;
	char			*options;
	char			*size;
	int				width;
	int				accuracy;
}					t_flags;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, \
								size_t n);
void				*ft_memccpy(void *fdt, \
								const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, \
								size_t n);
size_t				ft_strlcat(char *dst, const char *src, \
								size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);
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
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, \
								char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_factorial(int n);
int					ft_abs(int n);
int					ft_sqrt(int n);
int					ft_swap(int *i, int *j);
int					ft_sum(int *tab, size_t n);
int					ft_printf(const char *format, ...);
int					print_c(va_list ap, t_flags elem);
int					print_s(va_list ap, t_flags elem);
int					print_p(va_list ap, t_flags elem);
int					print_per(t_flags elem);
int					print_d(va_list ap, t_flags elem);
int					print_zd(va_list ap, t_flags elem);
int					print_hd(va_list ap, t_flags elem);
int					print_hhd(va_list ap, t_flags elem);
int					print_ld(va_list ap, t_flags elem);
int					print_lld(va_list ap, t_flags elem);
int					print_i(va_list ap, t_flags elem);
int					print_hi(va_list ap, t_flags elem);
int					print_hhi(va_list ap, t_flags elem);
int					print_li(va_list ap, t_flags elem);
int					print_lli(va_list ap, t_flags elem);
int					print_o(va_list ap, t_flags elem);
int					print_ho(va_list ap, t_flags elem);
int					print_hho(va_list ap, t_flags elem);
int					print_lo(va_list ap, t_flags elem);
int					print_llo(va_list ap, t_flags elem);
int					print_u(va_list ap, t_flags elem);
int					print_hu(va_list ap, t_flags elem);
int					print_hhu(va_list ap, t_flags elem);
int					print_lu(va_list ap, t_flags elem);
int					print_llu(va_list ap, t_flags elem);
int					print_sx(va_list ap, t_flags elem);
int					print_hsx(va_list ap, t_flags elem);
int					print_hhsx(va_list ap, t_flags elem);
int					print_lsx(va_list ap, t_flags elem);
int					print_llsx(va_list ap, t_flags elem);
int					print_bx(va_list ap, t_flags elem);
int					print_hbx(va_list ap, t_flags elem);
int					print_hhbx(va_list ap, t_flags elem);
int					print_lbx(va_list ap, t_flags elem);
int					print_llbx(va_list ap, t_flags elem);
void				print_llld(long long n);
void				print_lllo(unsigned long long n);
void				print_lllu(unsigned long long n);
void				print_lllsx(unsigned long long n);
void				print_lllbx(unsigned long long n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					padding_d(long long n, int s, t_flags elem);
int					padding_u(unsigned long long n, int s, t_flags elem);
int					padding_o(unsigned long long n, int s, t_flags elem);
int					padding_sx(unsigned long long n, int s, t_flags elem);
int					padding_bx(unsigned long long n, int s, t_flags elem);
int					dispatcher(t_flags elem, va_list ap);
int					check_sizes(char *str, char conv);
t_flags				fill_flags(const char *str);
t_flags				*get_flags(const char *str, int *ct);
int					get_next_line(const int fd, char **line);

#endif
