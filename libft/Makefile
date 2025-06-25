# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 17:39:45 by mcauchy           #+#    #+#              #
#    Updated: 2025/04/28 10:49:44 by macauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_isascii.c ft_memccpy.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
					ft_bzero.c ft_isdigit.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c \
					ft_calloc.c ft_isprint.c ft_memcmp.c  ft_putendl_fd.c ft_strdup.c  ft_strmapi.c ft_substr.c \
					ft_isalnum.c ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
					ft_isalpha.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_strcmp.c \
					ft_strcpy.c ft_str_is_numeric.c ft_split.c ft_striteri.c \

BONUS			=	ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS		=	$(BONUS:.c=.o)

NAME			=	libft.a

OBJ				=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

HEADER			=	libft.h

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar rc $@ $^
					ranlib $@

%.o				:	%.c $(HEADER)
					$(CC) $(CFLAGS) -o $@ -c $<

clean			:
					/bin/rm -f $(OBJ)
					/bin/rm -rf $(DIR_OBJ)
					/bin/rm -f $(BONUS_OBJS)

fclean			:	clean
					/bin/rm -f $(NAME)

re				:	fclean all

bonus			:	$(OBJ) $(BONUS_OBJS)
					ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY			:	all clean norme fclean re
