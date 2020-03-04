NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c
OBJFILES = ft_printf.o

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)
	ranlib $(NAME)

.PHONY: all

all: $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

debug: all
	$(CC) $(NAME) main.c -o debug
