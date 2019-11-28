FLAGS = -Wall -Werror -Wextra

NAME = get_next_line

$(NAME):
	gcc -c $(FLAGS) $(NAME).c -o $(NAME).o

all: $(NAME)

clean:
	@rm -f $(NAME).o

fclean: clean

re: fclean all

main:
	gcc $(FLAGS) main.c $(NAME).c libft/libft.a -I./ -o test
