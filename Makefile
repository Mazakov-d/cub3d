SRC_DIR=src
INC_DIR=include
OBJ_DIR=.obj
MLX_DIR=minilibx-linux

CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -I$(INC_DIR) -I$(MLX_DIR)

vpath %.c $(SRC_DIR) $(SRC_DIR)/parsing
vpath %.h $(INC_DIR)
vpath %.o $(OBJ_DIR)

SRCS =	main.c \
		map_parsing.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME=cub

.PHONY : all libs clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -I$(MLX_DIR) -lXext -lX11 -lm -o $(NAME)

libs:
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o : %.c $(INC_DIR)/cub.h Makefile | $(OBJ_DIR)
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