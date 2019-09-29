/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:20:46 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/29 17:36:23 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	t_fdes			data;
	static	t_list	db;

	if (!(data = ft_searchdb(fd, data))) //search add if not found return pointer
		return (-1);
	if (data.n > 0)
		ft_trimn(data.line); //trims till \n or \0
	else
	{
		if (data.end == 1)
		{
			ft_trimn(data.line);
	 		free //free data free lst[fd]
		}
		else
		{
			while (readbuf()) //return writes \0 and \ns to db->data
		}
	}
}
