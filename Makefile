# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 12:15:19 by ecabanas          #+#    #+#              #
#    Updated: 2023/01/03 12:19:23 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SRC_CLIENT	=	src/client.c src/utils.c
SRC_SERVER	=	src/server.c src/utils.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

#BONUS FILES
SRC_CLIENT_B	=	src/client_bonus.c src/utils.c
SRC_SERVER_B	=	src/server_bonus.c src/utils.c
OBJ_CLIENT_B	=	$(SRC_CLIENT_B:.c=.o)
OBJ_SERVER_B	=	$(SRC_SERVER_B:.c=.o)

HEADER		=	includes/minitalk.h
DEPS		=	$(addsuffix .d, $(basename $(notdir $(SRC))))	

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -MMD
AFLAGS		=	-L libft -lft
RM			=	rm -f
DEPS_DEL 	= 	./*.d ./src/*.d

#######################################################################################################################################
all: libft server client
bonus: libft server_bonus client_bonus

libft:
	make -C libft

-include $(DEPS)
server: $(OBJ_SERVER) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_SERVER) $(AFLAGS) -o $@

-include $(DEPS)
client: $(OBJ_CLIENT) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_CLIENT) $(AFLAGS) -o $@

-include $(DEPS)
server_bonus: $(OBJ_SERVER_B) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_SERVER_B) $(AFLAGS) -o $@

-include $(DEPS)
client_bonus: $(OBJ_CLIENT_B) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJ_CLIENT_B) $(AFLAGS) -o $@

clean:
	make -C libft clean
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B) $(DEPS_DEL)

fclean: clean
	make -C libft fclean
	$(RM) -rdf client server client_bonus server_bonus

tests: server client
	bash -c "sh tests/tests.sh"

re: fclean all

.PHONY: libft all bonus server client server_bonus client_bonus clean fclean tests re 
