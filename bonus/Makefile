##
## EPITECH PROJECT, 2020
## 105torus_2019
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c					\
		$(DSRC)105torus.c				\
		$(DSRC)get_arguments.c				\
		$(DSRC)resolve_with_bisection.c			\
		$(DSRC)resolve_with_newton.c			\
		$(DSRC)resolve_with_secante.c			\
		$(DSRC)tools.c					\
		$(DSRC)window.c					\
		$(DSRC)draw_rectangle.c				\
		$(DSRC)draw_disc.c

OBJ	=	$(SRC:.c=.o)

NAME	=	105torus

CFLAGS	+= -Wall -Wextra -I./include -l csfml-graphics -l csfml-system -l csfml-window

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lm $(CFLAGS)

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) tests/test_project.c -I./include -L./lib -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
