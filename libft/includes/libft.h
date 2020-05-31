#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 20

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>

# define FD_MAX 50

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;



void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *,
						size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
int						ft_lstsize(t_list *begin_list);



void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_swap_adress(char	**a, char	**b);



void					ft_count_nb_occurence(char *str, char *search,
						int *nb_oc);
int						ft_countwords(char const *s, char c);
char					*ft_fill_with(size_t size, char c);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_put_in_mask(char **mask3, char *temp2);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putwstr(wchar_t	*str);
void					ft_putwchar(wchar_t c);
void					ft_replace_char_with_char_in_str(char **str,
						char search, char replace);
char					*search_and_replace_one(char *str, char *old,
						char *new);
char					*search_and_replace_all(char *str, const char *old,
						const char *new);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
int						ft_strclen(const char *s, char c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strislower(char *str);
int						ft_strisupper(char *str);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoin_proper(char *s1, int free1, char *s2,
						int free2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
size_t					ft_strlen_secure(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *big,
						const char *little, size_t len);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
void					ft_strtoupper(char **str);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_print_error_exit(void (*function)(const char *),
						const char *str);
int						ft_nb_occur_char_in_str(char *str, char *search);
void					ft_print_error_fd_exit(void (*function)(const char *,
						int fd), const char *str, int fd);
char					*ft_strnstartcpy(char *s, size_t i);
char					*ft_read_all_file(int fd);
char					*ft_strdup_plus_char(const char *s1, char c);
char					**ft_strsplit_strict(char *str, char c);



int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isblank(int c);
int						ft_isdigit(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_isupper(int c);



int						ft_atoi(const char *str);
long					ft_latoi(const char *str);
int						ft_atoi_base(const char *str, int base);
char					*ft_itoa(int n);
char					*ft_itoa_base(int nb, unsigned int base);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_nb_power_nb(int nb, int power);
int						ft_binary_to_decimal(char *str);
char					*ft_itoa_b_llint(long long int nb,
						unsigned int base);
char					*ft_itoa_b_ullint(unsigned long long int nb,
						unsigned int base);
char					*ft_itoa_llint(long long int n);
char					*ft_itoa_ullint(unsigned long long int n);
int						ft_absolute(int nb);
double					ft_absolute_double(double nb);
int						ft_check_if_num(char	*str);
int						**ft_create_array(unsigned long x, unsigned long y);
void					ft_free_double_array(void **array);
void					ft_print_array_int(int **array, int x);
void					ft_print_array_bool(bool **array, int x);

typedef struct			s_dlist
{
	int					fd;
	char				*result;
	struct s_dlist		*next;
}						t_dlist;

typedef struct			s_gnl
{
	int					length;
	char				*buffer;
	t_dlist				*new;
	int					ret;
}						t_gnl;

int						get_next_line(const int fd, char **line,
						t_dlist *list);

#endif
