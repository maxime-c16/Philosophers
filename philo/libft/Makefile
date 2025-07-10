# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 17:39:45 by mcauchy           #+#    #+#              #
#    Updated: 2025/06/26 11:57:30 by macauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME		=	libft.a

# Compiler and flags
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
RM			=	/bin/rm -f

# Header file
HEADER		=	libft.h

# Source files
SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_str_is_numeric.c

# Bonus source files
BONUS		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Object files
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS:.c=.o)

# Colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[0;36m
RESET		=	\033[0m

# Build rules
all:		$(NAME)

$(NAME):	$(OBJS)
		@printf "$(YELLOW)Creating library $(NAME)...$(RESET)\n"
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@printf "$(GREEN)Library $(NAME) created successfully!$(RESET)\n"

%.o:		%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(OBJS) $(BONUS_OBJS)
		@printf "$(YELLOW)Creating library $(NAME) with bonus...$(RESET)\n"
		@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
		@ranlib $(NAME)
		@printf "$(GREEN)Library $(NAME) with bonus created successfully!$(RESET)\n"

# Clean rules
clean:
		@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
