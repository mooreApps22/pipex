NAME	= pipex
CC		= cc -Wall -Wextra -Werror -g
SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:.c=.o)
HEADER	= libft/include/libft.h include/pipex.h
IFLAG	= -I./include
LIBFT	= libft/libft.a

all:	$(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/ all

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(IFLAG) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(IFLAGS)

clean:
	@make -C libft/ clean
	@rm -f src/*.o
	@rm -f *.o

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all pipex clean fclean re libft
