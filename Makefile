SRC_DIR=src
INC_DIR=include
OBJ_DIR=.obj
MLX_DIR=minilibx-linux

CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -I$(INC_DIR) -I$(MLX_DIR)

vpath %.c $(SRC_DIR) $(SRC_DIR)/parsing $(SRC_DIR)/utils $(SRC_DIR)/graphic $(SRC_DIR)/utils/frees $(SRC_DIR)/utils/str $(SRC_DIR)/utils/inits  $(SRC_DIR)/graphic/ray_casting
vpath %.h $(INC_DIR)
vpath %.o $(OBJ_DIR)

SRCS =\
	main.c map_parsing.c init.c free_graphic.c ray_init.c\
	ft_calloc.c ft_free_tab.c ft_isalpha.c ft_isspace.c ft_split.c\
	ft_strchr_idx.c ft_strlen.c get_next_line.c putendl_fd.c\
	printf_err.c ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_strchr.c\
	ft_strdup.c ft_tablen.c is_char_in_str.c putstr_fd.c rm_nl.c\
	ft_strjoin.c ft_strndup.c ends_with.c ft_strncmp.c ft_atoi.c\
	ft_is_str_spaces.c free_context.c free_lines_lst.c init_context.c\
	fill_map.c fill_texture_data.c fill_file_content.c ft_strsdup.c\
	check_flood_fill.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME=cub3D

.PHONY : all libs clean fclean re debug

all: libs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -I$(MLX_DIR) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

libs:
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o : %.c $(INC_DIR)/cub.h $(INC_DIR)/ray_casting.h Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: 
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR) $(NAME)

debug:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "OBJ_DIR: $(OBJ_DIR)"
	@echo "NAME: $(NAME)"

re : fclean all