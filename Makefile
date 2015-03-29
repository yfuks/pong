#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/29 19:40:46 by yfuks             #+#    #+#              #
#    Updated: 2015/03/29 21:02:19 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pong

SRC = sources/*.c

HEAD = ./includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang

LIB = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): 
	$(CC) $(FLAGS) $(SRC) -I $(HEAD) -L $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

flcean: clean
	/bin/rm -f $(NAME)

re: fclean all