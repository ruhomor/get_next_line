# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 21:02:57 by kachiote          #+#    #+#              #
#    Updated: 2019/09/28 18:24:56 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

INCL = ./

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(NAME).c

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
