# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamici <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 09:16:30 by lamici            #+#    #+#              #
#    Updated: 2023/01/17 09:16:38 by lamici           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

PT1 :=	part_1/ft_atoi.c \
	part_1/ft_bzero.c \
	part_1/ft_calloc.c \
	part_1/ft_isalnum.c \
	part_1/ft_isalpha.c \
	part_1/ft_isascii.c \
	part_1/ft_isdigit.c \
	part_1/ft_isprint.c \
	part_1/ft_memchr.c \
	part_1/ft_memcmp.c \
	part_1/ft_memcpy.c \
	part_1/ft_memmove.c \
	part_1/ft_memset.c \
	part_1/ft_strchr.c \
	part_1/ft_strdup.c \
	part_1/ft_strlcat.c \
	part_1/ft_strlcpy.c \
	part_1/ft_strlen.c \
	part_1/ft_strncmp.c \
	part_1/ft_strnstr.c \
	part_1/ft_strrchr.c \
	part_1/ft_tolower.c \
	part_1/ft_toupper.c \
	part_1/ft_matlen.c

PT2 :=	part_2/ft_itoa.c \
	part_2/ft_putchar_fd.c \
	part_2/ft_putendl_fd.c \
	part_2/ft_putnbr_fd.c \
	part_2/ft_putstr_fd.c \
	part_2/ft_split.c \
	part_2/ft_striteri.c \
	part_2/ft_strjoin.c \
	part_2/ft_strmapi.c \
	part_2/ft_strtrim.c \
	part_2/ft_substr.c

BNS :=	bonus/ft_lstadd_back.c \
	bonus/ft_lstadd_front.c \
	bonus/ft_lstclear.c \
	bonus/ft_lstdelone.c \
	bonus/ft_lstiter.c \
	bonus/ft_lstlast.c \
	bonus/ft_lstmap.c \
	bonus/ft_lstnew.c \
	bonus/ft_lstsize.c
	
PTF :=	ft_printf/ft_printf.c \
	ft_printf/ft_char.c \
	ft_printf/ft_string.c \
	ft_printf/ft_unsigned.c \
	ft_printf/ft_path.c \
	ft_printf/ft_hexd.c \
	ft_printf/ft_digit.c \
	ft_printf/ft_matrix.c \

GNL :=	get_next_line/get_next_line.c

OBJ_S = $(PT1:.c=.o) $(PT2:.c=.o) $(PTF:.c=.o) $(GNL:.c=.o)

OBJ_B = $(BNS:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_S)
	ar -rcs $@ $^

%.o:%.c
	@$(CC) -c $(CFLAG) -I. $< -o $@

clean: 
	/bin/rm -f part_1/*.o
	/bin/rm -f part_2/*.o
	/bin/rm -f ft_printf/*.o
	/bin/rm -f get_next_line/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJ_B)
	ar -rcs $(NAME) $^

.PHONY: all clean fclean re bonus
