#include "get_next_line.h"

t_fdes    *ft_descnew(const int fd)
{
    t_fdes    *data;

	data = (t_fdes*)malloc(sizeof(*data));
    data->fd = fd;
    data->line = ft_strnew(0);
    data->n = 0;
    data->end = 0;
    return (data);
}

t_fdes    *dbsearch(const int fd, t_list **dbp, short int del) //del=0 adds element del=1 dels
{
    t_list        *db;

    db = *dbp;
    if ((db) && (db->content))
    {
        if (((t_fdes*)(db->content))->fd == fd)
            return ((t_fdes*)db->content);
    }
    while (db->next)
    {
        if (((t_fdes*)(db->next->content))->fd == fd)
            return (db->next->content); //returns element if found
        db = db->next;
    }
    if (del == 1) //free if delmode
    {
        ft_bzero(db->content, db->content_size);
        free(db->content);
        free(db);
    }
    else
        ft_lstadd(dbp, ft_lstnew(ft_descnew(fd), sizeof(t_fdes))); //add new if notfound
    return ((t_fdes*)(*dbp)->content);
}

void		srch_n_join(char **mbuf, t_fdes *data)
{
	char	*newline;
	char	*mem;
	char    *buf;

	buf = *mbuf;
	mem = buf;
	while (*mem)
	{
		if (*mem == '\n')
			data->n += 1;
		mem++;
	}
	if (data->line)
	{
        newline = ft_strjoin(data->line, buf);
        free(data->line);
        free(*mbuf);
    }
	else
	    newline = buf;
	//printf("%s", newline);
	data->line = newline;
}

char		*cut_n(t_fdes *data)
{
	char	*memas;
	char    *tofree;
	int		size;
	char	*laen;
	char    *resline;

	size = 0;
	memas = data->line;
	while ((*memas != '\n') && (*memas)) //ищем переход считаем размер результата
	{
        size++;
        memas++;
    }
	resline = ft_strnew(size); //выделяем память под результат
	memas = data->line; //для записи результата
	laen = resline;
	while ((*memas != '\n') && (*memas)) //записываем результат
		*laen++ = *memas++;
	if (*memas) //дописываем остаток в data->line
	{
		memas++; //пропускаем \n
		tofree = data->line;
		laen = ft_strnew(ft_strlen(data->line) - size); //выделяем память
		data->line = laen; //ставим указатель на начало
		while (*memas) //до конца строки записываем
			*laen++ = *memas++;
		free(tofree);
	}
	else //TODO если дочитали и вывели все static
    {
        free(data->line);
        data->line = ft_strnew(0);
    }
	if (data->n > 0)
	    data->n -= 1;
	else
	    if (data->end == 1)
	        data->end += 1;
	return (resline);
}

int			get_next_line(const int fd, char **line)
{
    t_fdes	*data;
    static	t_list	**db;
	char	*buf;

    if (!(db))
    {
        db = (t_list**)malloc(sizeof(*db));
        *db = ft_lstnew(data, sizeof(*data));
    }
    data = dbsearch(fd, db, 0);
	while (!(data->n) && !(data->end))
	{
		if (read(data->fd, buf = ft_strnew(BUFF_SIZE), BUFF_SIZE))
		{
		    //printf("%s\n", buf);
            if (ft_strlen(buf) < BUFF_SIZE)
				data->end = 1;
			srch_n_join(&buf, data);
		}
		else
			return (-1);
	}
	//printf("%s", data->line);
	*line = cut_n(data);
	//printf("%s", *line);
	if ((data->end == 2) && (data->n == 0))
	{
	    dbsearch(fd, db, 1);
        return (0); //free all i guess? :>
    }
	return (1);
}
