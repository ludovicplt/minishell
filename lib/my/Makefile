##
## EPITECH PROJECT, 2020
## makefile
## File description:
## my_makefile
##

CC 	=	gcc

CFLAGS 	=	-W -Werror -Wextra -Wall -I./includes

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_printf.c	\
		my_convertbase.c	\
		convert.c	\
		my_putpointer.c	\
		my_ess.c	\
		my_put_nbr_int.c	\
		my_putchar_int.c	\
		my_strdup.c	\
		my_str_isalnum.c


NAME 	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ) copy
	ar rc  $(NAME) $(OBJ)

copy:
	mkdir -p ../../includes
	cp includes/*.h ../../includes

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	 fclean all
