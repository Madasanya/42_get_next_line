#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line_prev(int fd, char **line);
char	*get_next_line(int fd);
void	ft_memmove_till_newline(char *l_to_m);
int		ft_return_prep(int bytes, char **tmp, char **line, int fd);
int		ft_check_array_input(char **tmp, char **line, char *buffer, int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int j);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);

#endif