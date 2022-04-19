NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -rf

INC_DIR = include
SRC_DIR = srcs
OBJ_DIR = obj

LIBFT = libft/libft.a
GNL = gnl/libgnl.a
LIB = -Lgnl -lgnl -Llibft -lft -lreadline $(LDFLAGS)
CPPFLAGS      = -I/usr/local/opt/readline/include
LDFLAGS       = -L/usr/local/opt/readline/lib

HEADERS = $(addprefix $(INC_DIR)/, \
	ansi_color_codes.h  \
	minishell.h \
)
UTIL_DIR = $(SRC_DIR)/utils
UTIL_SRC = $(addprefix $(UTIL_DIR)/, \
	ft_array_add.c \
	ft_array_dup.c \
	ft_array_size.c \
	ft_memdel.c \
	ft_split_custom.c \
	mini_deinit.c \
	mini_init.c \
)
STND_DIR = $(SRC_DIR)/standard
STND_SRC = $(addprefix $(STND_DIR)/, \
	ft_close.c  \
	ft_dup2.c  \
	ft_execve.c \
	ft_fork.c \
	ft_free.c  \
	ft_open.c \
	ft_pipe.c \
	ft_unlink.c  \
	ft_waitpid.c  \
)
SIGNAL_DIR = $(SRC_DIR)/signal
SIGNAL_SRC = $(addprefix $(SIGNAL_DIR)/,	\
	signal.c  \
)

PARSER_DIR = $(SRC_DIR)/parser
PARSER_SRC = $(addprefix $(PARSER_DIR)/,	\
	cmd_list_utils.c  \
	expand_cmd.c  \
	expand_token.c  \
	get_expansion.c  \
	mini_parser.c \
	trim_token.c  \
)
LEXER_DIR = $(SRC_DIR)/lexer
LEXER_SRC = $(addprefix $(LEXER_DIR)/, \
	assign_token.c  \
	check_token.c  \
	mini_lexer.c \
	set_token.c  \
)

HISTORY_DIR = $(SRC_DIR)/history
HISTORY_SRC = $(addprefix $(HISTORY_DIR)/,	\
	history.c \
)
EXECUTOR_DIR = $(SRC_DIR)/executor
EXECUTOR_SRC = $(addprefix $(EXECUTOR_DIR)/,	\
	builtin_exec.c \
	dup2_close.c \
	mini_executor.c \
	redirect_input.c  \
	redirect_output.c \
	wait_exit_status.c \
)
ENV_DIR = $(SRC_DIR)/env
ENV_SRC = $(addprefix $(ENV_DIR)/,	\
	ft_delenv.c \
	ft_getenv.c \
	ft_putenv.c \
)
BUILTIN_DIR = $(SRC_DIR)/builtin
BUILTIN_SRC = $(addprefix $(BUILTIN_DIR)/,	\
	builtin_utils.c \
	cd.c \
	echo.c \
	env.c  \
	exit.c \
	export.c \
	pwd.c  \
	unset.c  \
)
ROOT_SRCS = $(addprefix $(SRC_DIR)/,	\
	main.c \
)
SRCS = \
	$(ROOT_SRCS)	\
	$(BUILTIN_SRC)	\
	$(ENV_SRC)	\
	$(EXECUTOR_SRC)	\
	$(HISTORY_SRC)	\
	$(LEXER_SRC)	\
	$(PARSER_SRC)  \
	$(SIGNAL_SRC)  \
	$(STND_SRC)  \
	$(UTIL_SRC)  \

vpath %.c \
	$(SRC_DIR)	\
	$(BUILTIN_DIR)	\
	$(ENV_DIR)	\
	$(EXECUTOR_DIR)	\
	$(HISTORY_DIR)	\
	$(LEXER_DIR)	\
	$(PARSER_DIR)  \
	$(SIGNAL_DIR)  \
	$(STND_DIR)  \
	$(UTIL_DIR)  \

# Color and format
BOLD = \e[1m
PURPLE = \e[1;35m
GREEN = \e[1;32m
PINK_TEXT = \e[38;2;255;124;212m
NEWLINE = \e[1K\r

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@make -s -C ./libft
	@make -s -C ./gnl
	@printf "$(NEWLINE)$(PURPLE)Successfully created $(PINK_TEXT)$@'s object files$(PURPLE)!"
	@printf "\n$(PURPLE)Creating $(PINK_TEXT)$@$(PURPLE)!\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_FLAGS) $(OBJS) $(LIB) $(LIBFT) $(GNL) $(CPPFLAGS) -o $@
	@printf "$(NEWLINE)$(GREEN)Successfully created $(GREEN)$@$(GREEN)!\n$(NO_COLOR)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "$(NEWLINE)$(PURPLE)Create $(PINK_TEXT)$@ $(PURPLE)from $(PINK_TEXT)$<"

clean :
	@$(RM) $(OBJ_DIR)
	@rm -f libft/libft.a
	@rm -f gnl/libgnl.a
	@printf "$(NEWLINE)$(PURPLE)Cleaning $(PINK_TEXT)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(NAME)
	@printf "$(NEWLINE)$(PURPLE)Cleaning $(PINK_TEXT)$(NAME)\n"

re : fclean all

norm:
	@norminette $(MAIN) $(SRCS)

.PHONY: all clean fclean re norm
