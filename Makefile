# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbascaul <nbascaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:09:34 by nbascaul          #+#    #+#              #
#    Updated: 2020/10/12 16:25:16 by nbascaul         ###   ########.fr        #
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


		

OBJ		= $(SRC:.c=.o)
CMP		= gcc #llvm-gcc
FLAGS	= -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[1;31;40m -------------- FINIIIII  GG. ---------------\033[0m"
%.o: %.c
	$(CMP) -I. -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
