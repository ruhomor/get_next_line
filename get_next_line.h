#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct		s_ldb
{
	int				fd;
	char			*cut;
	struct s_ldb	*next;
}					t_ldb;

t_ldb		*create_db(const int fd);
char		*search_n(char **n, char *cut);
int		read_line(const int fd, char **line, char *cut);
t_ldb		*search_db(t_ldb *db, const int fd);
int		get_next_line(const int fd, char **line);

#endif
