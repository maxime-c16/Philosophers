# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 14:32:46 by macauchy         #+#    #+#              #
#    Updated: 2025/06/25 14:32:46 by macauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		=	Philosophers

# Source files and directories
FILES		=	Philosophers.c free.c monitoring.c time.c
SRC_DIR		=	srcs
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))

# Object files
OBJ_DIR		=	.objs
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Header files
HEADER		=	includes/Philosophers.h

# Compiler and flags
CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
DEBUG		=	-fsanitize=address
RM			=	/bin/rm -rf

# Libraries
LDFLAGS		=	-Llibft -lft

# Colors for output
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[0;36m
WHITE		=	\033[0;37m
RESET		=	\033[0m

# Build rules
all:		$(NAME)

$(NAME):	$(OBJS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME)...$(RESET)\n"
		@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Compilation successful!$(RESET)\n"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
		@mkdir -p $(OBJ_DIR)
		@printf "$(CYAN)Compiling $<...$(RESET)\n"
		@$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug:		$(OBJS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME) with debug flags...$(RESET)\n"
		@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Debug compilation successful!$(RESET)\n"

# Clean rules
clean:
		@$(MAKE) -C libft clean --no-print-directory -s
		@printf "$(RED)Cleaning object files...$(RESET)\n"
		@$(RM) $(OBJ_DIR)
		@printf "$(GREEN)Object files cleaned!$(RESET)\n"

fclean:		clean
		@$(MAKE) -C libft fclean --no-print-directory -s
		@printf "$(RED)Removing executable $(NAME)...$(RESET)\n"
		@$(RM) $(NAME)
		@printf "$(GREEN)$(NAME) removed successfully!$(RESET)\n"

re:			fclean all

.PHONY:		all clean fclean re debug
