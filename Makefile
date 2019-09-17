NAME = players/jwatkyn.filler

SRCS = srcs/main.c \
	srcs/parsing.c \
	srcs/update.c \
	srcs/positions.c \
	srcs/printing.c \
	srcs/analysis.c \
	srcs/strategy.c

FLAGS = -Wall -Wextra -Werror -I./includes

OBJS = $(SRCS:.c=.o)

all: make_lib $(NAME)

make_lib:
		make -C libft

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) libft/libft.a
	@echo "Filler done"

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I./includes

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(OBJS)
	/bin/rm -rf $(NAME)

re: fclean all
