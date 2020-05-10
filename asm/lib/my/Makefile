##
## EPITECH PROJECT, 2019
## CPool_Day10_2019
## File description:
## Makefile
##

SRC	=	my_strlen.c	\
		my_strcat.c	\
		my_strndup.c	\
		my_getline.c	\
		my_strncmp.c	\
		my_strdup.c		\
		my_strncpy.c	\
		my_strcpy.c	\
		my_findchr.c	\
		str_to_word_array.c	\
		str_to_word_array_sep.c	\
		my_getnbr.c	\
		my_strcmp.c	\
		my_trimline.c \
		itoa.c \
		nblen.c

NAME = libmy.a

OBJ	=	$(SRC:.c=.o)

LIB = -L./ -lmy

CFLAGS += -W -Wall -Wextra -pedantic -I./ -g3

DEBUG += -W -Wall -Wextra -pedantic -g3

all : $(NAME)

$(NAME) : $(OBJ)
	cp my.h ../../include/
	ar rc libmy.a $(OBJ)
	mv $(NAME) ../
	rm -f $(OBJ)

clean :
	rm -f src/*.gc*
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f print
	rm -f tests/unit_tests

re : fclean all

debug :
	make -C ./ re
	gcc $(MAIN) -o print -I./include $(LIB) $(DEBUG)