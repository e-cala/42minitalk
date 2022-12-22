# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 12:15:19 by ecabanas          #+#    #+#              #
#    Updated: 2022/12/21 20:02:05 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SRC_CLIENT	=	src/client.c src/utils.c
SRC_SERVER	=	src/server.c src/utils.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
HEADER		=	includes/minitalk.h
DEPS		=	$(addsuffix .d, $(basename $(notdir $(SRC))))	

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -MMD
AFLAGS		=	-L libft -lft
RM			=	rm -f
DEPS_DEL 	= 	./*.d ./src/*.d

#######################################################################################################################################
all: libft server client

libft:
	make -C libft

-include $(DEPS)
server: $(OBJ_SERVER) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_SERVER) $(AFLAGS) -o $@

-include $(DEPS)
client: $(OBJ_CLIENT) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_CLIENT) $(AFLAGS) -o $@

clean:
	make -C libft clean
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEPS_DEL)

fclean: clean
	make -C libft fclean
	$(RM) -rdf client server

tests: server client
	bash -c "sh tests/tests.sh"

re: fclean all

.PHONY: libft all clean fclean re
