NAME = lem-in
HEADER = lem-in.h
SRC = main.c bfs.c get_next_line.c read.c read1.c read2.c utilities.c pathes.c mv.c utilities1.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./libft
	@make clean -C ./libft
	@$(CC) $(FLAGS) -c $(SRC) 
	@$(CC) -o $(NAME) $(SRC) $(LIBFT)
	make clean
clean:
		@rm -f *.o
fclean:
		@make clean
		@rm -f $(NAME)
re:
		@make fclean 
		@make all
		@make clean
