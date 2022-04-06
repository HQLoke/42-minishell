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
# include "get_next_line.h"
# include "libft.h"

extern char	**environ;

//* Macro definitions
//* LESSLESS   <<
//* LESS       <
//* GREATGREAT >>
//* GREAT      >
# define LESSLESS   1
# define LESS       2
# define GREATGREAT 3
# define GREAT      4
# define SUCCESS    99
# define FAILURE    100

typedef struct s_env
{
	char				*env_var;
	char				*value;
	struct s_env		*next;
	struct s_env		*prev;
}	t_env;

typedef struct s_mini
{
	t_env	*env_head;
	char	*pwd;

	t_list	*pipeline_head;

	t_list	*redirect;
	char	**cmd_args;
	char	**path;

	pid_t	process_id;
	int		in_fd;
	int		out_fd;
	int		exit_status;
	int 	write;
}	t_mini;

//* /srcs/env
void	env_deinit(t_env **head);
char	*env_get_value(t_env *head, char *env_var);
void	env_init(t_env **head);
void	env_set_value(t_env **head, char *env_var, char *new_value);
void	env_new_value(t_env **head, char *env_var, char *value);
int 	update_env_value(t_env *env, char *tmp, char *env_var);

//* /srcs/error
int		check_ends(const char *str, int *exit);
int		check_pipe(const char *str, int *exit);
int		check_quotes(const char *str, int *exit);
int		check_redirection(const char *str, int *exit);
int		error_handling(const char *input);

//* /srcs/executor
void	child_dup2_close(t_mini *mini, int fd[2], int last_fd, int cmd);
int		execute_builtin(t_mini *mini);
void	executor(t_mini *mini, int cmd);
int		redirect_input(t_list *redirect);
int		redirect_output(t_list *redirect);
void	wait_exit_status(t_mini *mini);

//* /srcs/init_deinit
void	mini_deinit(t_mini **mini);
void	mini_init(t_mini **mini);

//* /srcs/parser
int		count_cmd_args(t_list *head);
void	expand_dollar(char **cmd_args, t_list *expansion);
void	extract_expansion(t_mini *mini, char **cmd_args, t_list **expansion);
void	process_line(t_mini *mini, const char *line);
void	set_cmd_args_array(t_mini *mini);
void	trim_quotes(char **cmd_args);

//* /srcs/signal
void	ft_signal(void);
void	sigquit_handler(t_mini **mini);

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
size_t	ft_array_size(char **array);
void	ft_error(const char *str, int fd, int *exit);
void	ft_memdel(void **ptr);
void	ft_new_addback(t_list **head, char *content, int type);
void	ft_tokenizer(t_list **head, const char *input, char delim);
int		argv_len(char* argv[]);

//* /srcs/builtin
void	cd_error(char *s1, char *s2, char *s3);
int		builtin_cd(char **cmd, t_env *env);
int		builtin_echo(char **cmd, t_env *env);
int		builtin_env(char **cmd, t_env *env);
int		builtin_exit(char **cmd, t_env *env);
int		builtin_pwd(char **cmd, t_env *env);
int		builtin_unset(char **cmd, t_env *env);
int 	builtin_export(char **cmd, t_env *env);
int		get_arglen(char *s1, char *s2);
char	*add_front(int fd, char *value, char s);
char	*add_end(int fd, char *value, char c);
void	fill_list(t_env *env, char argv);
int		check_list(t_env *env, t_env *new_env, char *argv, int i);
int		check_var_syntax(char *str);
void	print_not_valid(char *cmd, char *str);
#endif