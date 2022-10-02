# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 12:15:19 by ecabanas          #+#    #+#              #
#    Updated: 2022/10/02 13:08:35 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk
SRC		=	src/server.c
OBJ		=	$(SRC:.c=.o)
HEADER	=	includes/minitalk.h
DEPS	=	$(addsuffix .d, $(basename $(notdir $(SRC))))	

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -MMD
RM		=	rm -f
DEPS_DEL = ./*.d ./src/*.d

#######################################################################################################################################
all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
		$(MAKE) -C libft all
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft -lft
		./$(NAME)

clean:
	$(MAKE) -C libft all clean
	$(RM) $(OBJ) $(DEPS_DEL)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
