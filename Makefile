CFLAGS = -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3 #-Wall -Wextra -Werror
CC = gcc

SRC_FILES =	main.c \
			verif_map.c \
			error.c \
			verif_shape.c \
			parsing_map.c \
			parsing_map_utils.c \
			utils.c \
			check_file.c \
			display.c \
			map_modifier.c \
			path_finding1.c \
			path_finding2.c \
			path_finding3.c \
			path_finding4.c \
			utils_path_finding.c \
			raycast.c \
			player.c \
			textures.c \
			draw_minimap.c \
			draw_minimap_utils.c \
			draw_minimap_pathfinding.c \
			draw_minimap_circle.c \
			hook.c \
			window.c \
			render.c \
			render_utils.c \
			player_straf.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))

SRCS_DIR = srcs
OBJS_DIR = objs
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
MLX_DIR = $(LIB_DIR)/mlx
INCLUDES_DIR = includes

NAME = cub3D

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ -I$(INCLUDES_DIR) $<

all: $(NAME)

debug: fclean libft mlx $(OBJS)
	${CC} ${CFLAGS} -fsanitize=address -g -o ${NAME} -I${INCLUDES_DIR} ${OBJS} -I${LIB_DIR} -lft -lmlx -framework OpenGL -framework Appkit -lmlx

libft:
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/get_next_line.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/ft_malloc.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIB_DIR)

mlx:
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/mlx.h $(INCLUDES_DIR)
	cp $(MLX_DIR)/libmlx.a $(LIB_DIR)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -I$(INCLUDES_DIR) $(OBJS) -L$(LIB_DIR) -lft -lmlx -framework OpenGL -framework Appkit -lmlx

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
