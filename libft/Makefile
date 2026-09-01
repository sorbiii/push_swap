# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 17:22:34 by nadamczy          #+#    #+#              #
#    Updated: 2025/01/06 10:59:01 by nadamczy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -c
FLAGS = -Wall -Wextra -Werror
AR = ar rc

SRC = *.c 

OBJ = *.o

all: $(NAME)

$(NAME): 
	$(CC)  $(FLAGS) $(SRC)
	$(AR)  $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
