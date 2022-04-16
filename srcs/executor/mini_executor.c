/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:05 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 12:14:48 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_single(t_cmd *command_head)
{
	int	process;

	g_environ->exit_status = 0;
	if (builtin_exec(command_head) == 1)
		return ;
	process = ft_fork();
	if (process == 0)
	{
		single_dup2_close(command_head);
		ft_execve(command_head->cmd_args);
	}
}

static void	execute_multiple(t_cmd *command_head)
{
	t_cmd		*tmp;
	int			fd[2];
	int			process;
	static int	last_fd;

	tmp = command_head;
	while (tmp)
	{
		if (tmp->cmd_num >= 0)
			ft_pipe(fd);
		process = ft_fork();
		if (process == 0)
		{
			child_dup2_close(tmp, fd, last_fd);
			g_environ->exit_status = 0;
			if (builtin_exec(tmp) == 0)
				ft_execve(tmp->cmd_args);
		}
		parent_close(fd, &last_fd, tmp->cmd_num);
		tmp = tmp->next;
	}
}

//* Forking process starts here
//* If N > 1,  cmd_num = 0  means first process
//*            cmd_num > 0  means middle process
//*            cmd_num = -1 means last process
//* If N == 1, cmd_num = -2 means first & last, or one and only process
void	mini_executor(t_cmd *command_head)
{
	if (command_head->cmd_args == NULL)
		return ;
	if (command_head->cmd_num == -2)
		execute_single(command_head);
	else
		execute_multiple(command_head);
	wait_exit_status();
}
