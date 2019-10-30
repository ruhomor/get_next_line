/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:20:46 by kachiote          #+#    #+#             */
/*   Updated: 2019/10/16 18:52:39 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdes	*ft_descnew(const int fd, char **line, size_t len, short int end)
{
	t_fdes	*data;
	char	*buf;

	data = (t_fdes*)malloc(sizeof(*data));
	data->fd = fd;
	data->line = line;
	data->len = len;
	data->n = 0;
	data->end = 0;
	while (len--)
	{
		if(*buf == '\n')
			data->n++;
	}
	return (data);
}

t_fdes	*dbsearch(const int fd, t_list **dbp, short int del) //del=0 adds element del=1 dels
{
	t_list		*db;

	db = *dbp;
	if (db)
	{
		if (((t_fdes*)db->content)->fd == fd)
			return (db->content);
	}
	while (db->next)
	{
		if (((t_fdes*)db->next->content)->fd == fd)
			return ((t_fdes*)db->next->content); //returns element if found
		db = db->next;
	}
	if (del == 1) //free if delmode
	{
		ft_bzero(db->content, db->content_size);
		free(db->content);
		free(db);
	}
	else
		ft_lstadd(dbp, ft_lstnew(ft_descnew(fd, 0, 0, 0), sizeof(t_fdes))); //new if nfound
	return ((t_fdes*)(*dbp)->content);
}

int		get_next_line(const int fd, char **line)
{
	t_fdes			*data;
	static	t_list	**db;
	size_t			bytes;
	size_t			len;
	t_fdes			*datafound;

	data = ft_descnew(fd, line, 0, 0);
	if ((!(db)) || (!(*db)))
	{
		db = (t_list**)malloc(sizeof(*db));
		*db = ft_lstnew(data, sizeof(*data));
	}
	datafound = dbsearch(fd, db, 0);
	datacreated = dbsearch(228, db, 0);
}
