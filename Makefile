NAME = minishell

CC        	  = gcc
CFLAGS    	  = -Wall -Wextra -Werror -g3 -fsanitize=address
RM            = rm -f

INC 	      = -Iinclude -Ignl -Ilibft $(CPPFLAGS)
GNL_DIR       = ./gnl
LIBFT_DIR     = ./libft
LIB           = -Lgnl -lgnl -Llibft -lft -lreadline $(LDFLAGS)
CPPFLAGS      = -I/usr/local/opt/readline/include
LDFLAGS       = -L/usr/local/opt/readline/lib

MAIN = srcs/main.c
BUILTIN_DIR   	= srcs/builtin/
ENV_DIR       	= srcs/env/
ERROR_DIR     	= srcs/error/
EXECUTOR_DIR  	= srcs/executor/
HISTORY_DIR		= srcs/history/
LEXER_DIR		= srcs/lexer/
PARSER_DIR      = srcs/parser/
SIGNAL_DIR		= srcs/signal/
STANDARD_DIR  	= srcs/standard/
UTILS_DIR     	= srcs/utils/
SRCS = $(addprefix $(BUILTIN_DIR), builtin_utils.c cd.c echo.c env.c exit.c export.c pwd.c unset.c) \
	   $(addprefix $(ENV_DIR), ft_delenv.c ft_getenv.c ft_putenv.c) 								\
	   $(addprefix $(EXECUTOR_DIR), builtin_exec.c dup2_close.c mini_executor.c 		    		\
	   								redirect_input.c redirect_output.c wait_exit_status.c)			\
	   $(addprefix $(HISTORY_DIR), history.c)									   					\
	   $(addprefix $(LEXER_DIR), assign_token.c check_token.c set_token.c mini_lexer.c)				\
	   $(addprefix $(PARSER_DIR), cmd_list_utils.c expand_cmd.c expand_token.c get_expansion.c 		\
	    						  mini_parser.c trim_token.c) 										\
	   $(addprefix $(SIGNAL_DIR), signal.c)							  								\
	   $(addprefix $(STANDARD_DIR), ft_close.c ft_dup2.c ft_execve.c ft_fork.c ft_free.c ft_open.c  \
	   								ft_pipe.c ft_unlink.c ft_waitpid.c) 							\
	   $(addprefix $(UTILS_DIR), ft_array_add.c ft_array_dup.c ft_array_size.c ft_memdel.c 			\
	   							 ft_split_custom.c mini_deinit.c mini_init.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C $(GNL_DIR) -s
	@make re -C $(LIBFT_DIR) -s
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(GNL_DIR) -s
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(GNL_DIR) -s
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all

norm:
	@norminette $(MAIN) $(SRCS)

.PHONY: all clean fclean re norm