SRCS_DIR = ./srcs/
SRCS =	read_mapfile.c\
		utils.c\
		mlx_utils.c\
		free.c\
		init_envs.c\
		init_texure.c\
		init_map.c\
		init_map2.c\
		cub3d.c\
		minimap.c\


OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

MLX_DIR = minilibx-linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

NAME = cub3D 
RM = rm -f

all:	${NAME}		

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) 

clean:
		@${RM} ${OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@${RM} ${OBJS} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re