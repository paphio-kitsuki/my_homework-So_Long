NAME	= so_long
MLX_DIR	= mlx_linux
SRCS	= color.c create.c delete.c draw.c error.c ft_itoa.c ft_lstclear.c ft_lstnew.c ft_lstsize.c ft_putstrln.c ft_strncmp.c ft_strrchr.c get_next_line_utils.c get_next_line.c image.c main.c map.c player.c possible.c repaint.c search.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -L$(PWD)/$(MLX_DIR) -lmlx -lXext -lX11
ifneq ($(OS),Windows_NT)
 ifneq ($(shell uname),Linux)
  MLX_DIR	= mlx_mac
  CFLAGS	= -Wall -Wextra -Werror -L$(PWD)/$(MLX_DIR) -lmlx -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -D ISMAC
 endif
endif

all: ${NAME}

${NAME}: ${OBJS}
	cd ${PWD}/${MLX_DIR} && ${MAKE}
	${CC} $^ ${CFLAGS} -o $@

clean:
	${RM} ${OBJS}
	cd ${PWD}/${MLX_DIR} && ${MAKE} $@
	cd ${PWD}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean
