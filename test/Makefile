NAME = TEST

CFLAGS =  #-g -fsanitize=address

INC = -I../include -I../libft
LIB = -L../libft -lft -lreadline
SRC = TEST.c

all:
	@make re -C ../libft -s
	@gcc ${CFLAGS} $(INC) -o $(NAME) $(SRC) $(LIB)
	@./$(NAME)

clean:
	@rm -f $(NAME)