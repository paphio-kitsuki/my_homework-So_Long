NAME	= so_long
MLX_DIR	= mlx_linux
MAN_SRC = time_man.c
MAN_OBJ	= $(MAN_SRC:.c=.o)
BNS_SRC = time_bonus.c
BNS_OBJ	= $(BNS_SRC:.c=.o)
SRCS	= color.c create.c delete.c draw.c error.c ft_itoa.c ft_lstclear.c ft_lstnew.c ft_lstsize.c ft_putstrln.c ft_strncmp.c ft_strrchr.c get_framesize.c get_next_line_utils.c get_next_line.c image.c main.c map.c player.c possible.c print_extra.c repaint.c save_count.c search.c
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

ifdef WITH_BONUS
 CFLAGS += -lrt -D ISBONUS=1
 SRCS += $(BNS_SRC)
 OBJS += $(BNS_OBJ)
else
 SRCS += $(MAN_SRC)
 OBJS += $(MAN_OBJ)
endif

all: ${NAME}

${NAME}: ${OBJS}
	cd ${PWD}/${MLX_DIR} && ${MAKE}
	${CC} $^ ${CFLAGS} -o $@

clean:
	${RM} ${OBJS} ${BNS_OBJ}
	cd ${PWD}/${MLX_DIR} && ${MAKE} $@
	cd ${PWD}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus:
	@${MAKE} WITH_BONUS=1

.PHONY: re all clean fclean bonus
