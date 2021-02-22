##
## EPITECH PROJECT, 2021
## minishell
## File description:
## makefile
##

CC	=	gcc

SRC	=	main.c	\
		src/exec.c	\
		src/fonc.c	\
		src/built.c	\
		src/tool.c	\
		src/directory.c	\
		src/core.c

CFLAG	=	-W -Wall -Werror -Wextra -pedantic -g3 -g -I./includes -L./lib/my -lmy

NAME	=	mysh

all:	build

build:
	make -C ./lib/my
	$(CC) -o $(NAME) $(SRC) $(CFLAG)

clean:
	rm -rf *.o
	find . \( -name "*~" -o -name "*.o" \) -delete
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	rm -rf .*.un~
	make fclean -C ./lib/my

re:	fclean all
