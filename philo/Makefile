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

NAME		=	philo

FILES		=	Philosophers.c free.c monitoring.c time.c routine.c utils.c \
				fork.c singleton.c
SRC_DIR		=	srcs
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR		=	.objs
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

HEADER		=	includes/Philosophers.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
DEBUG		=	-fsanitize=address
RM			=	/bin/rm -rf

LDFLAGS		=	-Llibft -lft

RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[0;36m
WHITE		=	\033[0;37m
RESET		=	\033[0m

all:	$(NAME)

$(NAME):	$(OBJS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME)...$(RESET)\n"
		@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Compilation successful!$(RESET)\n"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER) libft/libft.h
		@mkdir -p $(OBJ_DIR)
		@printf "$(CYAN)Compiling $<...$(RESET)\n"
		@$(CC) $(CFLAGS) -c $< -o $@

debug:		$(OBJS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME) with debug flags...$(RESET)\n"
		@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Debug compilation successful!$(RESET)\n"

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

rebonus:	fclean bonus

.PHONY:		all clean fclean re debug
