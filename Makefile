SRCS	=	srcs/gnl/get_next_line.c \
			srcs/gnl/get_next_line_utils.c \
			srcs/move/cam.c \
			srcs/move/key.c \
			srcs/move/player.c \
			srcs/parsing/check_map.c \
			srcs/parsing/convert_color.c \
			srcs/parsing/error_parsing.c \
			srcs/parsing/get_other.c \
			srcs/parsing/get_path.c \
			srcs/parsing/parsing.c \
			srcs/parsing/parsing2.c \
			srcs/parsing/utils_parsing.c \
			srcs/raycasting/draw.c \
			srcs/raycasting/raycasting.c \
			srcs/screenshot/screenshot.c \
			srcs/sprite/sprite.c \
			srcs/sprite/sprite2.c \
			srcs/utils/init.c \
			srcs/utils/init2.c \
			srcs/utils/utils.c \
			srcs/utils/utils2.c \
			srcs/utils/utils3.c \
			srcs/utils/utils4.c \
			srcs/utils/free.c \
			srcs/main.c

OBJ	= ${SRCS:.c=.o}

NAME = cub3D

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

# LIBS = -I /usr/X11/include -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit
LIBS = -L ./mlx -I . -I ./mlx -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd

$(NAME):	${OBJ}
			make -C mlx/
			$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

all:		${NAME}

clean:		
			make clean -C mlx/
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}
			rm -rf *.bmp

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean bonus
