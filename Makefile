NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c
OBJFILES = ft_printf.o
LIBFT = libft/libft.a

$(NAME): $(OBJFILES)
	make -C libft
	ar rcs $(NAME) $(OBJFILES) libft/*.o
	ranlib $(NAME)

.PHONY: all

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJFILES)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) debug

re: fclean all

debug: all
	$(CC) -g $(CFILES) main.c $(LIBFT) -o debug