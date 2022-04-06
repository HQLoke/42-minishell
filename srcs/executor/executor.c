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

static void	parent_close(int fd[2], int *last_fd, int cmd)
{
	if (cmd == 0)
	{
		close(fd[1]);
		*last_fd = fd[0];
	}
	else if (cmd > 0)
	{
		close(*last_fd);
		close(fd[1]);
		*last_fd = fd[0];
	}
	else if (cmd == -1)
	{
		close(*last_fd);
	}
}

//* Forking process starts here
//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	executor(t_mini *mini, int cmd)
{
	int			fd[2];
	int			process;
	static int	last_fd;

	if (cmd >= 0)
		ft_pipe(fd);
	mini->process_id = ft_fork();
	if (mini->process_id == 0)
	{
		child_dup2_close(mini, fd, last_fd, cmd);
		mini->exit_status = 0;
		if (execute_builtin(mini) == 0)
			ft_execve(mini->cmd_args, mini->path);
	}
	parent_close(fd, &last_fd, cmd);
}
