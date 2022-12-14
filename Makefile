# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 12:15:19 by ecabanas          #+#    #+#              #
#    Updated: 2022/10/02 13:40:02 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SRC_CLIENT	=	src/client.c
SRC_SERVER	=	src/server.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
HEADER		=	includes/minitalk.h
DEPS		=	$(addsuffix .d, $(basename $(notdir $(SRC))))	

CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra -MMD
AFLAGS		=	-L libft -lft
RM		=	rm -f
DEPS_DEL 	= 	./*.d ./src/*.d

#######################################################################################################################################
all: libft server client

libft:
	make -C libft


server: $(OBJ_SERVER) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $< $(AFLAGS) -o server

client: $(OBJ_CLIENT) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $< $(AFLAGS) -o client

clean:
	make -C libft clean
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEPS_DEL)

fclean: clean
	make -C libft fclean
	$(RM) -rdf client server

re: fclean all

.PHONY: libft all clean fclean re
