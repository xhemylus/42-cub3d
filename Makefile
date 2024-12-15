# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:47:27 by vpericat          #+#    #+#              #
#    Updated: 2022/12/02 12:07:09 by vpericat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
PROJECT_NAME = CUB3D

#FILES
FILES = main.c input.c \
		math.c draw.c \
		engine.c ray.c \
		map.c collision.c \
		renderer.c walls.c \
		parse.c checker.c \
		tools.c
HEADER = include/cub3d.h

#PATHS
SRC_DIR = source
OBJ_DIR = object

#OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

#MISCELLANEOUS
DEBUGFLAGS = -O3
PREPROCFLAGS = -Iinclude -Ilibft -Iminilibx $(DEBUGFLAGS)
LIBFT = libft/libft.a 
MLX = minilibx/libmlx.a
LINKERFLAGS = -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit $(DEBUGFLAGS)
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(DEBUGFLAGS)

##	VISUALS	##
_BANNER = \033[1m\033[34m[$(PROJECT_NAME)]\033[39m
_BUILDBANNER = $(_BANNER)\033[32m[BUILD]\033[39m —\033[0m
_CLEANBANNER = $(_BANNER)\033[33m[REMOVED]\033[39m —\033[0m

##	RULES	##
all: libft mlx $(OBJ_DIR) $(NAME)

libft:
	@make -skC libft

mlx:
	@make -skC libft

$(LIBFT):
	@make -skC libft

$(MLX):
	@make -skC minilibx

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(PREPROCFLAGS) -c $< -o $@
	@echo "$(_BUILDBANNER) $@"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "$(_BUILDBANNER) $@ folder"

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LINKERFLAGS)
	@echo "$(_BUILDBANNER) $@"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_CLEANBANNER) $(OBJ_DIR) folder"
	@make -sC libft extclean
	@echo "$(_CLEANBANNER) minilibx.a"
	@echo "$(_CLEANBANNER) minilibx objects"
	@make -sC minilibx clean
	
fclean: clean
	@make -sC libft extfclean
	@rm -f $(NAME)
	@echo "$(_CLEANBANNER) $(NAME)"
	
re: fclean all

nice: all clean
	@clear
	@echo "\033[34m\033[1m[NICE]\033[39m —\033[0m clear"

exe: re
	@clear
	@./minishell

.PHONY: clean fclean all re nice libft
