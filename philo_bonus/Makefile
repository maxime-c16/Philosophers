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

FILES_BONUS	=	Philosophers_bonus.c free_bonus.c monitoring_bonus.c \
				time_bonus.c routine_bonus.c utils_bonus.c singleton.c
SRC_BONUS	=	srcs_bonus
SRCS_BONUS	=	$(addprefix $(SRC_BONUS)/, $(FILES_BONUS))

OBJ_DIR		=	.objs
OBJS_BONUS	=	$(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

HEADER_B	=	includes_bonus/Philosophers_bonus.h

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

$(NAME):	$(OBJS_BONUS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME)...$(RESET)\n"
		@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Compilation successful!$(RESET)\n"

$(OBJ_DIR)/%.o:	$(SRC_BONUS)/%.c $(HEADER_B) libft/libft.h
		@mkdir -p $(OBJ_DIR)
		@printf "$(CYAN)Compiling $<...$(RESET)\n"
		@$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(OBJS_BONUS)
		@$(MAKE) -C libft --no-print-directory -s
		@printf "$(YELLOW)Compiling $(NAME) bonus...$(RESET)\n"
		@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME)
		@printf "$(GREEN)Bonus compilation successful!$(RESET)\n"

$(OBJ_DIR)/%.o:	$(SRC_BONUS)/%.c $(HEADER_B) libft/libft.h
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

.PHONY:		all clean fclean re debug bonus
