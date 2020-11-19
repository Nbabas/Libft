# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:09:34 by nbascaul          #+#    #+#              #
#    Updated: 2020/11/19 16:23:43 by nbascaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strlen.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa_base.c \
		ft_lltoa.c \

SRC_BONUS =		ft_lstnew.c		\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c	\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c		\


		

OBJ		= $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC		= clang
FLAGS	= -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re