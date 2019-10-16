/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:22:33 by kachiote          #+#    #+#             */
/*   Updated: 2019/10/16 18:33:16 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h> //xyuuu

typedef	struct	s_fdes
{
	const int	fd;
	char		**line;
	size_t		n;
	short int	end;
	size_t		len;
}				t_fdes;

# define BUFF_SIZE 16

#endif
