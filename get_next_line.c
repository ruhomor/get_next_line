/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:20:46 by kachiote          #+#    #+#             */
/*   Updated: 2019/10/09 17:06:44 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdes	*ft_searchdb(t_list **db, const int fd, short int tofree)
{
	while (*db)
	{
		if ((*db)->content->fd == fd)
			break;
		*db = (*db)->next;
	}
	if (tofree == 1)
	{
		ft_bzero(*db->content, size);
		free(*db->content); //TODO free content->!!!???!!!
		free(*db);
	}
	else
		return ((*db)->content);
	return (NULL);
}

t_fdes	*ft_initdb(const int fd, t_list **db)
{
	t_fdes			*data;

	if ((!(*db)) && (!(data = ft_searchdb(db, fd, 0)))) //protect
	{
		data->fd = fd;
		data->n = 0;
		data->end = 0;
		data->lensize = 0;
		ft_lstnew(data, sizeof(t_fdes));
	}
	return (data);
}

int		ft_trimnw(t_fdes *data)
{
	char	*str;
	char	*buf;
	char	*stcb;

	str = data->line;
	buf = str;
	while ((*str) && (*str != '\n'))
	{
		ft_putchar_fd(*str++, 1);
		data->lensize -= 1;
	}
	if (*str == '\n')
		data->n -= 1;
	if (data->lensize > 0) //reallocation
	{
		if (!(stcb = ft_strnew(data->lensize)))
			return (-1);
		while (*str)
			*stcb++ = *str++;
		free(data->line);
		data->line = stcb;
	}
}

int		get_next_line(const int fd, char **line)
{
	t_fdes			*data;
	static	t_list	**db;

	if (!(data = ft_initdb(fd, db))) //search add if not found return pointer
		return (-1);
	if (data->n > 0)
		ft_trimnw(data->line); //TODO trims till \n or \0 and writes
	else
	{
		if (data->end == 1)
		{
			ft_trimnw(data->line);//TODO trims till \n or \0 and writes (size collision?)
			//destroy sring
	 		ft_searchdb(db, fd, 1); //TODO free data free lst[fd]
		}
		else
		{
			while (readbuf()) //return writes \0 and \ns to db->data
		}
	}
}
