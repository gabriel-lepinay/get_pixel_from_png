##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

SRC = 	src/main.c			\
		src/app.c

NAME = open_img

OBJ = $(SRC:.c=.o)

LDFLAGS = -lpng

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
