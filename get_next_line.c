/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:20:46 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/28 21:12:35 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**memre(char **line, int bs)
{
	char	*newline;
	char	*buf;

	bs++;
	if (!(newline = (char*)malloc(sizeof(newline) * (BUFF_SIZE * bs))))
		return (NULL);
	buf = newline;
	while (**line)
		*buf++ = **line++;
	free(*line);
	return (newline);
}

int		get_next_line(const int fd, char **line)
{
	int			bytes;
//lst
	if (!(line = memre(line, fds[fd]++)))
		return (-1);

	bytes = read(fd, *line, BUFF_SIZE);
}
