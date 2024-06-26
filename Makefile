# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagea <lagea@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 01:08:23 by lagea             #+#    #+#              #
#    Updated: 2024/06/18 15:36:12 by lagea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

ARCH := $(shell uname -m)

# Cible pour Mac ARM
ifeq ($(ARCH),arm64)
    MLX			= -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
	LIB			= lib/lib_x86/libmlx42.a
else
# Cible pour Mac Intel
    MLX			= -lglfw -L"/Users/lagea/homebrew/opt/glfw/lib/"
	LIB 		= lib/lib_x64/libmlx42.a
endif

NAME		= fdf

SRC_DIR		= src/
BONUS_DIR	= bonus/
OBJ_DIR		= obj/
OBJB_DIR	= obj_bonus/
INC_DIR		= inc/

SRC 		= $(wildcard $(SRC_DIR)*.c) 
#SRC 		= main.c
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
SRCB 		= $(wildcard $(BONUS_DIR)*.c) 
OBJB		= $(SRCB:$(BONUS_DIR)%.c=$(OBJB_DIR)%.o)

LIBFT 		= lib/libft.a
LIBFT_PATH 	= libft/

CC			= gcc
RM			= rm -f
C_FLAGS		= -Wall -Wextra -Werror
INCS 		= -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_fdf
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling FdF... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

TOTAL_FILES 	:= $(words $(wildcard $(SRC_DIR)*.c))
CURRENT_FILE 	:= 0


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCS) -Imlx -c $< -o $@
	$(call progress_bar_fdf)

all: $(LIBFT) $(NAME)

bonus : $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) $(LIBFT) $(LIB) $(MLX) -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

$(BONUS):$(LIBFT) $(OBJB)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJB) -Llib/ -lft $(MLX) -g -o $(BONUS)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"
	
$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(NC)"
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "$(ORANGE)Cleaning objects for Libft...$(NC)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)Cleaned objects Libft!$(NC)"
	@echo "$(ORANGE)Cleaning objects for FdF...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@$(RM) $(OBJB_DIR)*.o
	@echo "$(GREEN)Cleaned FdF objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Libft...$(NC)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned Libft!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for FdF...$(NC)"
	@$(RM) $(NAME) $(BONUS)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)
	@echo "$(BLUE)Fully cleaned FdF!$(NC)"

re: fclean all

.PHONY: all clean fclean re