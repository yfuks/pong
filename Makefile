#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/29 19:40:46 by yfuks             #+#    #+#              #
#    Updated: 2015/03/29 23:28:32 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pong

SRC =	sources/draw.c				\
		sources/put_pixel.c			\
		sources/draw_rectangle.c 	\
		sources/hook.c				\
		sources/main.c				\
		sources/draw_dotted.c

HEAD = ./includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang

LIB =  /usr/x11/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -I $(HEAD) -L $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all