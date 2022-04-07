NAME = minishell

CC        	  = gcc
CFLAGS    	  = #-g3 -fsanitize=address
#-Wall -Wextra -Werror
RM            = rm -f

INC 	      = -Iinclude -Ilibft $(CPPFLAGS)
LIBFT_DIR     = ./libft
LIB           = -Llibft -lft -lreadline $(LDFLAGS)
CPPFLAGS      = -I/usr/local/opt/readline/include
LDFLAGS       = -L/usr/local/opt/readline/lib

MAIN = srcs/main.c
BUILTIN_DIR   	= srcs/builtin/
ENV_DIR       	= srcs/env/
ERROR_DIR     	= srcs/error/
EXECUTOR_DIR  	= srcs/executor/
INIT_DEINIT_DIR = srcs/init_deinit/
LEXER_DIR		= srcs/lexer/
PARSER_DIR      = srcs/parser/
SIGNAL_DIR		= srcs/signal/
STANDARD_DIR  	= srcs/standard/
UTILS_DIR     	= srcs/utils/
SRCS = $(addprefix $(BUILTIN_DIR), cd.c echo.c env.c exit.c export.c export_utils.c pwd.c unset.c)  \
	   $(addprefix $(ENV_DIR), env_deinit.c env_get_value.c env_init.c env_set_value.c) 	        \
	   $(addprefix $(ERROR_DIR), check_ends.c check_pipe.c check_quotes.c 					        \
	   							 check_redirection.c error_handling.c) 						        \
	   $(addprefix $(EXECUTOR_DIR), child_dup2_close.c execute_builtin.c executor.c 		        \
	   								redirect_input.c redirect_output.c wait_exit_status.c)			\
	   $(addprefix $(INIT_DEINIT_DIR), mini_deinit.c mini_init.c)									\
	   $(addprefix $(LEXER_DIR), assign_token.c check_token.c mini_lexer.c)							\
	   $(addprefix $(PARSER_DIR), count_cmd_args.c expand_dollar.c expand_token.c extract_expansion.c 				\
	   							  process_line.c set_cmd_args_array.c trim_quotes.c) 				\
	   $(addprefix $(SIGNAL_DIR), signal.c)							  								\
	   $(addprefix $(STANDARD_DIR), ft_access.c ft_close.c ft_dup2.c ft_execve.c ft_fork.c   		\
	   								ft_free.c ft_open.c ft_pipe.c ft_unlink.c ft_waitpid.c) 		\
	   $(addprefix $(UTILS_DIR), ft_array_size.c ft_error.c ft_error_exit.c ft_memdel.c ft_new_addback.c    \
	   							 ft_tokenizer.c ft_check_argv.c)			                      
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C $(LIBFT_DIR) -s
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all

norm:
	@norminette $(MAIN) $(SRCS)

.PHONY: all clean fclean re norm