# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodney <frodney@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 12:53:01 by frodney           #+#    #+#              #
#    Updated: 2021/08/02 14:38:52 by frodney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER) -I$(MLX_HEADER)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADER = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_macos/
MLX_HEADER = $(MLX_DIR)

HEADER_DIR = ./includes/
HEADER =  $(addprefix $(HEADER_DIR), fdf.h)

SRC_DIR = ./sources/
SRC_LIST = main.c utils.c draw_map.c read_map.c \

SRC = $(SRC_DIR)/$(SRC_LIST)

OBJ_DIR = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME) #$(FLAGS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(RESET)"
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

norm:
	@$(MAKE) -sC $(LIBFT_DIR) norm
	@norminette $(SRC_DIR)*.c $(HEADER_DIR)*.h

fclean: clean
	@rm -f $(MLX)
	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

gc:
	@$(MAKE) fclean
	@git add .
	@git commit -m "fast commit"
	@echo "$(GREEN)commit was commited$(RESET)"

gp:
	@$(MAKE) gc
	@git push
	@echo "$(GREEN)fast commit was pushed$(RESET)"
