#include "get_next_line.h"

t_ldb		*create_db(const int fd)
{
	t_ldb	*db;

	if (!(db = (t_ldb*)malloc(sizeof(t_ldb))))
		return (NULL);
	db->fd = fd;
	db->cut = ft_strnew(BUFF_SIZE);
	db->next = NULL;
	return(db);
}

char		*search_n(char **n, char *cut)
{
	char	*str;

	if ((*n = ft_strchr(cut, '\n')) != NULL)
	{
		str = ft_strsub(cut, 0, *n - cut);
		ft_strcpy(cut, ++(*n));
	}
	else
	{
		str = ft_strnew(ft_strlen(cut) + 1);
		ft_strcat(str, cut);
		ft_strclr(cut);
	}
	return (str);
}

int			readline(const int fd, char **line, char *cut)
{
	char			buf[BUFF_SIZE + 1];
	char			*n;
	char			*tmp;
	int			bytes;

	n = NULL;
	bytes = 1;
	*line = search_n(&n, cut);
	while ((!n) && ((bytes = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[bytes] = '\0';
		if ((n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(cut, ++n);
			ft_strclr(--n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || bytes < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	if (ft_strlen(cut) || ft_strlen(*line) || bytes)
		return (1);
	return (0);
}

t_ldb			*search_db(t_ldb *db, const int fd)
{
	t_ldb	*data;

	data = db;
	while (data->fd != fd)
	{
		if (data->next == NULL)
			data->next = create_db(fd);
		data = data->next;
	}
	return(data);
}

int			get_next_line(const int fd, char **line)
{
	static t_ldb	*db;

	if ((fd < 0) || (!(line)))
		return (-1);
	if (!db)
		db = create_db(fd);
	return(readline(fd, line, search_db(db, fd)->cut));
}
