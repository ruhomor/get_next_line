#include <stdlib.h>

typedef    struct        s_list
{
    void            *content;
    size_t            content_size;
    struct s_list    *next;
}                     t_list;

typedef    struct    s_fdes
{
    int            fd;
    char        *line;
    size_t        n;
    short int    end;
    size_t        len;
}                t_fdes;

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *bdst;
    unsigned char *bsrc;

    if (src || dst)
    {
        bdst = (unsigned char*)dst;
        bsrc = (unsigned char*)src;
        while (n--)
        {
            *bdst = *bsrc;
            bdst++;
            bsrc++;
        }
        return (dst);
    }
    return (NULL);
}

void    *ft_backwardsmemcpy(void *dst, const void *src, size_t n)
{
    unsigned char *bdst;
    unsigned char *bsrc;

    if (src || dst)
    {
        bdst = (unsigned char*)dst;
        bsrc = (unsigned char*)src;
        bdst += (n - 1);
        bsrc += (n - 1);
        while (n--)
        {
            *bdst = *bsrc;
            bdst--;
            bsrc--;
        }
        return (dst);
    }
    return (NULL);
}

#define BUFF_SIZE 16

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    if (dst || src)
    {
        if (dst <= src)
            return (ft_memcpy(dst, src, len));
        else
            return (ft_backwardsmemcpy(dst, src, len));
    }
    return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = (unsigned char*)s;
	while (n--)
	{
		*p = 0;
		p++;
	}
}

t_list    *ft_lstnew(void const *content, size_t content_size)
{
    t_list    *root;

    if (!(root = (t_list*)malloc(sizeof(*root))))
        return (NULL);
    if (content)
    {
        if (!(root->content = (void*)malloc(sizeof(void) * content_size)))
        {
            free(root);
            return (NULL);
        }
        root->content = ft_memmove(root->content, content, content_size);
        root->content_size = content_size;
    }
    else
    {
        root->content = NULL;
        root->content_size = 0;
    }
    root->next = NULL;
    return (root);
}

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char    a;
    unsigned char    *d;

    d = (unsigned char*)b;
    a = (unsigned char)c;
    while (len--)
    {
        *d = a;
        d++;
    }
    return (b);
}

void    *ft_memalloc(size_t size)
{
    void *suka;

    if (!(suka = malloc(size)))
        return (NULL);
    suka = ft_memset(suka, '\0', size);
    return (suka);
}

char    *ft_strnew(size_t size)
{
    char    *cuckoo;

    if (!(cuckoo = (char*)ft_memalloc(size + 1)))
        return (NULL);
    return (cuckoo);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*meme;

	meme = *alst;
	*alst = new;
	new->next = meme;
}

t_fdes    *ft_descnew(const int fd, char **line, size_t len, short int end)
{
    t_fdes    *data;
    char    *buf;

<<<<<<< HEAD
	data = (t_fdes*)malloc(sizeof(*data));
=======
    data = (t_fdes*)malloc(sizeof(*data));
>>>>>>> fa9bfd4f24454f06475659a7116c07827d2d366e
    data->fd = fd;
    data->line = line;
    data->len = len;
    data->n = 0;
    data->end = 0;
    while (len--)
    {
        if(*buf == '\n')
		{
            data->n++;
			buf++;
		}
    }
    return (data);
}

t_fdes    *dbsearch(const int fd, t_list **dbp, short int del) //del=0 adds element del=1 dels
{
    t_list        *db;

    db = *dbp;
    if (db)
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
        ft_lstadd(dbp, ft_lstnew(ft_descnew(fd, 0, 0, 0), sizeof(t_fdes))); //add new if notfound
    return ((t_fdes*)(*dbp)->content);
}

void		srch_n_join(char *buf, t_fdes *data)
{
	char	*newline;
	char	*mem;

	mem = buf;
	while (*mem)
	{
		if (*mem == '\n')
			data->n++;
	}
	newline = ft_strjoin(data->line, buf);
	free(data->line);
	free(buf);
	data->line = newline;
}

char		**cut_n(t_fdes *data)
{
	char	**resline;
	char	*memas;
	int		size;
	char	*laen;

	memas = data->line;
	while ((*memas != '\n') && (*memas))
		size++;
	*resline = ft_strnew(size);
	memas = data->line;
	laen = *resline;
	while ((*memas != '\n') && (*memas))
		*laen++ = *memas++;
	if (*memas)
	{
		memas++;
		laen = ft_strnew(ft_strlen(data->line) - 1 - size);
		while (*memas)
			*laen++ = *memas++;
		free(data->line);
		data->line = laen;
	}
	else
		free(data->line);
	return (resline);
}

int			get_next_line(const int fd, char **line)
{
    t_fdes	*data;
    static	t_list	**db;
    size_t	bytes;
    size_t	len;
	char	*buf;

    if (!(db))
    {
        db = (t_list**)malloc(sizeof(*db));
        *db = ft_lstnew(data, sizeof(*data));
    }
    data = dbsearch(fd, db, 0);
	while (!(data->n) || !(data->end))
	{
		if (bytes = read(data->fd, buf = ft_strnew(BUFF_SIZE), BUFF_SIZE))
		{
			if (bytes < BUFF_SIZE)
				data->end = 1;
			srch_n_join(buf, data);
		}
		else
			return (-1);
	}
	line = cut_n(data);
	if ((data->end == 1) && (data->n == 0))
		return (0); //free all i guess? :>
	return (1);
}

int main()
{
  char  **laenn;
  char  *buf;
  int  len = 2, suka = 2;
  laenn = (char**)malloc(sizeof(*laenn));
  *laenn = ft_strnew(len);
  buf = *laenn;
  while (suka--)
      *buf++ = 'a';
  get_next_line(1, laenn);
  return (0);
}
