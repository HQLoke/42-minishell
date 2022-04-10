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

typedef struct s_environ
{
	int		num_var;
	char	**env_var;
	int		exit_status;
}	t_environ;

t_environ	*g_environ;

enum e_token{heredoc = 1, input, append, trunc, piping, command, argument};
typedef struct s_env
{
	char			*env_var;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	t_env	*env_head; //Delete later
	char	*pwd;

	t_list	*redirect;  //Free in child if exit
	char	**cmd_args; //Free in child if exit

	pid_t	process_id;
	int		in_fd;
	int		out_fd;
}	t_mini;

//! ************************NEW REVAMP************************
//* /srcs/lexer
void	assign_token(t_list **token_head);
void	check_token(t_list **token_head);
void	set_token(t_list **token_head);
void	mini_lexer(char *input, t_list **token_head);

//* /srcs/parser
void	expand_cmd(t_list *node);
void	expand_token(t_list *node);
void	mini_parser(t_list *token_head);
void	trim_token(char *content);
//! ************************NEW REVAMP************************

//* /srcs/env
void	environ_deinit(void);
void	environ_init(char **envp);
int		ft_delenv(char *env_key);
char	*ft_getenv(char *env_key);
int		ft_putenv(char *env_var);

//* /srcs/executor
void	child_dup2_close(t_mini *mini, int fd[2], int last_fd, int cmd);
int		builtin_parent(t_mini *mini);
int		builtin_child(t_mini *mini);
int		builtin(t_mini *mini);
void	mini_executor(t_mini *mini, int cmd);
int		redirect_input(t_list *redirect);
int		redirect_output(t_list *redirect);
void	wait_exit_status(t_mini *mini);

//* /srcs/signal
void	ft_signal(void);
void	sigquit_handler(void);

//* /srcs/standard
void	ft_access(const char *filename, int mode);
void	ft_close(int fd);
void	ft_dup2(int oldfd, int newfd);
void	ft_execve(char **cmd_args, char **path);
pid_t	ft_fork(void);
void	ft_free(void *ptr);
int		ft_open(const char *path, int flag, int mode);
void	ft_pipe(int fd[2]);
void	ft_unlink(const char *pathname);
pid_t	ft_waitpid(pid_t pid, int *wstatus, int options);

//* /srcs/utils
char	**ft_array_dup(char **src_array, int num_var);
size_t	ft_array_size(char **array);
void	ft_error_exit(char *error_msg);
void	ft_memdel(void **ptr);
void	ft_new_addback(t_list **head, char *content, int type);
void	ft_split_custom(t_list **head, const char *input, char delim);
int		argv_len(char *argv[]);

//* /srcs/builtin
void	cd_error(char *s1, char *s2, char *s3);
int		builtin_cd(char **cmd, t_env *env);
int		builtin_echo(char **cmd, t_env *env);
int		builtin_env(void);
int		builtin_exit(char **cmd, t_env *env);
int		builtin_pwd(char **cmd, t_env *env);
int		builtin_unset(char **cmd, t_env *env);
int		builtin_export(char **cmd, t_env *env);
int		get_arglen(char *s1, char *s2);
char	*add_front(int fd, char *value, char s);
char	*add_end(int fd, char *value, char c);
void	fill_list(t_env *env, char argv);
int		check_list(t_env *env, t_env *new_env, char *argv, int i);
int		check_var_syntax(char *str);
void	print_not_valid(char *cmd, char *str);
#endif