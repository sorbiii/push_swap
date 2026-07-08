NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR  = ar rcs

SRC = algorithm.c cheapest_for_a.c move_functions.c rotate.c main.c operations.c utils.c cheapest.c utils_for_algorithm.c sec_utils.c sort_five.c valid_num.c

OBJ = ${SRC:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(LIBFT): 
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re libft

