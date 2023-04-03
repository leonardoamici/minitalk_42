NAME = minitalk

LIBFT = Libft/libft.a

SER = server.c

CLN = client.c

SER_B = server_bonus.c

CLN_B = client_bonus.c
	
FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): libcomp comp

norm:
		@cd source/ && norminette

libcomp:
		@make -C Libft
	
comp:
	gcc $(FLAGS) $(SER) $(LIBFT) -o server
	gcc $(FLAGS) $(CLN) $(LIBFT) -o client
            
libclean:
		@make clean -C Libft
		
clean:		libclean

libfclean:
		@make fclean -C Libft

fclean:   	clean libfclean
		rm -rf server
		rm -rf client

bonus:
	gcc $(FLAGS) $(SER_B) $(LIBFT) -o server
	gcc $(FLAGS) $(CLN_B) $(LIBFT) -o client
	
re: fclean all

.SILENT:
