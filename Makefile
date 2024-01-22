NAME = minitalk
CC = cc
LIBFT = Libft/libft.a
SER = server.c
CLN = client.c
SER_B = server_bonus.c
CLN_B = client_bonus.c
FLAGS = -Wall -Werror -Wextra -g

OBJ_C = $(CLN:.c=.o)
OBJ_S = $(SER:.c=.o)
OBJ_CB = $(CLN_B:.c=.o)
OBJ_SB = $(SER_B:.c=.o)

all: $(NAME)

$(NAME): libcomp client server	

libcomp:
		@make -C Libft

server: $(OBJ_S)
		$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o server

client: $(OBJ_C)
		$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o client

bonus: libcomp client_bonus server_bonus 

server_bonus: $(OBJ_SB)
		$(CC) $(FLAGS) $(OBJ_SB) $(LIBFT) -o server_bonus

client_bonus: $(OBJ_CB)
		$(CC) $(FLAGS) $(OBJ_CB) $(LIBFT) -o client_bonus

clean: 
		@make clean -C Libft
		rm -rf $(OBJ_S) $(OBJ_C) $(OBJ_SB) $(OBJ_CB)

fclean: clean 
		@make fclean -C Libft
		rm -rf server client server_bonus client_bonus

re: fclean all

.PHONY: all re clean fclean bonus