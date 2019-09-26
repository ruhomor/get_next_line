# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 21:02:57 by kachiote          #+#    #+#              #
#    Updated: 2019/09/24 16:43:58 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_backwardsmemcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_isdigit \
		ft_atoi \
		ft_isalpha \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_isupper \
		ft_islowercase \
		ft_toupper \
		ft_tolower \
		ft_memalloc \
		ft_memdel \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strtrim \
		ft_isspace \
		ft_strsplit \
		ft_itoa \
		ft_putchar_fd \
		ft_putchar \
		ft_putstr_fd \
		ft_putstr \
		ft_putendl_fd \
		ft_putendl \
		ft_putnbr_fd \
		ft_putnbr \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap \
		ft_writenbr \
		ft_countwords \
		ft_deldel

SRCS = $(patsubst %, %.c, $(FUNCS))

OUT = $(patsubst %, %.o, $(FUNCS))

INCL = ./

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

%.o:%.c -I$(INCL)
	@gcc $(FLAGS) $(INCL) $< -o $@

$(NAME): $(OUT)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
