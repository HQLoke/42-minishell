/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:05:42 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 17:26:07 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>
# include "ansi_color_codes.h"
# include "libft.h"

struct s_environ	*g_environ;
enum e_token{heredoc = 1, input, append, trunc, piping, command, argument};

typedef struct s_environ
{
	int		num_var;
	char	**env_var;
	int		exit_status;
}	t_environ;

typedef struct s_cmd
{
	int				cmd_num;
	int				in_fd;
	int				out_fd;
	t_list			*redirect;
	char			**cmd_args;
	struct s_cmd	*next;
}	t_cmd;

//* /srcs/builtin
void	cd_error(char *s1, char *s2, char *s3);
void	builtin_cd(t_cmd *node);
void	builtin_echo(t_cmd *node);
void	builtin_env(t_cmd *node);
void	builtin_exit(t_cmd *node);
void	builtin_export(t_cmd *node);
void	builtin_pwd(t_cmd *node);
void	builtin_unset(t_cmd *node);

//* /srcs/env
int		ft_delenv(char *env_key);
char	*ft_getenv(char *env_key);
int		ft_putenv(char *env_var);

//* /srcs/executor
int		builtin_exec(t_cmd *node);
void	child_dup2_close(t_cmd *node, int fd[2], int last_fd);
void	mini_executor(t_cmd *command_head);
void	parent_close(int fd[2], int *last_fd, int cmd);
int		redirect_input(t_list *redirect);
int		redirect_output(t_list *redirect);
void	single_dup2_close(t_cmd *node);
void	wait_exit_status(void);

//* /srcs/lexer
void	assign_token(t_list **token_head);
void	check_token(t_list **token_head, bool *lexer_ok);
void	set_token(t_list **token_head);
int		mini_lexer(char *input, t_list **token_head);

//* /srcs/parser
void	expand_cmd(t_list *node);
void	expand_token(t_list *node, t_list *expansion);
void	get_expansion(char *content, t_list **expansion);
void	make_cmd_list(t_list *token_head, t_cmd **command_head, int pipe_count);
void	mini_parser(t_list *token_head, t_cmd **command_head);
void	trim_token(char *content);
void	unmake_cmd_list(t_cmd **command_head);

//* /srcs/signal
void	ft_signal(void);
void	sigquit_handler(void);

//* /srcs/standard
void	ft_access(const char *filename, int mode);
void	ft_close(int fd);
void	ft_dup2(int oldfd, int newfd);
void	ft_execve(char **cmd_args);
pid_t	ft_fork(void);
void	ft_free(void *ptr);
int		ft_open(const char *path, int flag, int mode);
void	ft_pipe(int fd[2]);
void	ft_unlink(const char *pathname);
pid_t	ft_waitpid(pid_t pid, int *wstatus, int options);

//* /srcs/utils
char	**ft_array_add(char **src_array, char *str);
char	**ft_array_dup(char **src_array, int num_var);
size_t	ft_array_size(char **array);
void	ft_memdel(void **ptr);
void	ft_split_custom(t_list **head, const char *input, char delim);
void	mini_deinit(void);
void	mini_init(t_list **token_head, t_cmd **command_head, char **envp);
#endif