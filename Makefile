CFLAGS = 
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
			raycast.c \
			player.c \
			textures.c \
			hook.c \
			window.c \
			render.c \
			render_utils.c \
			player_straf.c

SRC_FILES_BONUS =	main_bonus.c \
					verif_map_bonus.c \
					error_bonus.c \
					verif_shape_bonus.c \
					parsing_map_bonus.c \
					parsing_map_utils_bonus.c \
					utils_bonus.c \
					check_file_bonus.c \
					display_bonus.c \
					map_modifier_bonus.c \
					path_finding1_bonus.c \
					path_finding2_bonus.c \
					path_finding3_bonus.c \
					path_finding4_bonus.c \
					utils_path_finding_bonus.c \
					raycast_bonus.c \
					player_bonus.c \
					textures_bonus.c \
					draw_minimap_bonus.c \
					draw_minimap_utils_bonus.c \
					draw_minimap_pathfinding_bonus.c \
					draw_minimap_circle_bonus.c \
					hook_bonus.c \
					window_bonus.c \
					render_bonus.c \
					render_utils_bonus.c \
					player_straf_bonus.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SRC_FILES_BONUS))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES_BONUS))))

SRCS_DIR = srcs
SRCS_DIR_BONUS = srcs_bonus
OBJS_DIR = objs
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
MLX_DIR = $(LIB_DIR)/mlx
INCLUDES_DIR = includes
INCLUDES_DIR_BONUS = includes_bonus

NAME = cub3D

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ -I$(INCLUDES_DIR) $<

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ -I$(INCLUDES_DIR_BONUS) $<

all: $(NAME)

debug: fclean libft mlx $(OBJS)
	${CC} ${CFLAGS} -fsanitize=address -g -o ${NAME} -I${INCLUDES_DIR} ${OBJS} -I${LIB_DIR} -lft -lmlx -lXext -lm -lz -lX11

libft:
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/get_next_line.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/ft_malloc.h $(INCLUDES_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIB_DIR)

libft_bonus:
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.h $(INCLUDES_DIR_BONUS)
	cp $(LIBFT_DIR)/get_next_line.h $(INCLUDES_DIR_BONUS)
	cp $(LIBFT_DIR)/ft_malloc.h $(INCLUDES_DIR_BONUS)
	cp $(LIBFT_DIR)/libft.a $(LIB_DIR)

mlx:
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/mlx.h $(INCLUDES_DIR)
	cp $(MLX_DIR)/libmlx.a $(LIB_DIR)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -I$(INCLUDES_DIR) $(OBJS) -L$(LIB_DIR) -lft -lmlx -lXext -lm -lz -lX11

bonus: libft_bonus mlx $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) -I$(INCLUDES_DIR_BONUS) $(OBJS_BONUS) -L$(LIB_DIR) -lft -lmlx -lXext -lm -lz -lX11

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
