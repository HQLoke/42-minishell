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

//* Forking process starts here
//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	mini_executor(t_cmd *command_head)
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
			// if (!builtin_child(tmp))
				ft_execve(tmp->cmd_args);
		}
		parent_close(fd, &last_fd, tmp->cmd_num);
		tmp = tmp->next;
	}
	wait_exit_status();
}
