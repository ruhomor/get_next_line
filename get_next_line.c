/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:20:46 by kachiote          #+#    #+#             */
/*   Updated: 2019/10/16 17:03:51 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_descnew(const int fd, char **line, size_t len, short int end)
{
	t_fdes	*data;
	char	*buf;

	data->fd = fd;
	data->line = **line;
	data->len = len;
	data->n = 0;
	data->end = 0;
	while (len--)
	{
		if(*buf == '\n')
			data->n++;
	}
}

int		dbsearch(const int fd, t_list *db, short int del)
{
	short int found;

	found = 0;
	while (*db)
	{
		if (db->data->fd == fd)
			return (db->data);
		db = db->next;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	t_fdes			*data;
	static	t_list	*db;
	size_t			bytes;
	size_t			len;

	data = ft_descnew(fd, line, 0, 0);
	if ((!(db)) || (!(*db)))
		ft_lstnew(data, sizeof(*data));
}
