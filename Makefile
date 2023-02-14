NAME	= so_long
MLX_DIR	= ./mlx
SRC		= color.c create.c delete.c draw.c error.c ft_itoa.c ft_lstclear.c ft_lstnew.c ft_lstsize.c ft_putstrln.c ft_strncmp.c ft_strrchr.c get_next_line_utils.c get_next_line.c image.c main.c map.c player.c possible.c repaint.c search.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAG	= -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx -lXext -lX11

all: ${NAME}

${NAME}: ${OBJS}
	cd ${MLX_DIR}
	${MAKE}
	cd ..
	${CC} ${CFLAGS} $^ -o $@

clean:
	${RM} ${OBJS}
	cd ${MLX_DIR}
	${MAKE} $@
	cd ..

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean
