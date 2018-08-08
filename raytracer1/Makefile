##
## Makefile for Makefile in /home/jeremy.elkaim/raytracer1
## 
## Made by jeremy elkaim
## Login   <jeremy.elkaim@epitech.net>
## 
## Started on  Mon Feb 27 10:31:34 2017 jeremy elkaim
## Last update Fri Mar 17 11:12:56 2017 jeremy elkaim
##
NAME    = raytracer1

INC	= -Iinclude -lc_graph_prog -lm

CFLAGS += -W -Wall -Wextra -Werror -pedantic

SRC    = src/my_put_pixel.c	\
	 src/draw_line.c	\
	 src/main.c		\
	 src/calc_dir_vector.c	\
	 src/sphere.c		\
	 src/plane.c		\
	 src/light.c		\

OBJ    = $(SRC:.c=.o)

all:	 $(NAME)

$(NAME): $(OBJ)
	 gcc $(OBJ) -o $(NAME) $(INC) $(CFLAGS)

clean:
	 rm -rf $(OBJ)

fclean:	 clean
	 rm -rf $(NAME)

re:	 fclean all

.PHONY:	 all clean fclean re
