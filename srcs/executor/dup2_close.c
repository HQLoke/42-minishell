/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:29:49 by hloke             #+#    #+#             */
/*   Updated: 2022/04/15 08:51:34 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* used for cmd_num == -2 only
//* if N == 1, cmd = -2 means one and only process    1   4
void	single_dup2_close(t_cmd *node)
{
	if (node->cmd_num != -2)
		return ;
	node->in_fd = redirect_input(node->redirect);
	node->out_fd = redirect_output(node->redirect);
	if (node->in_fd != -1)
	{
		ft_dup2(node->in_fd, STDIN_FILENO);
		ft_close(node->in_fd);
	}
	if (node->out_fd != STDOUT_FILENO)
	{
		ft_dup2(node->out_fd, STDOUT_FILENO);
		ft_close(node->out_fd);
	}
}

static void	child_dup2_close_continue(t_cmd *node, int fd[2], int last_fd)
{
	if (node->cmd_num > 0 || node->cmd_num == -1)
	{
		if (node->in_fd != -1)
		{
			ft_dup2(node->in_fd, STDIN_FILENO);
			ft_close(node->in_fd);
			ft_close(last_fd);
		}
		else
		{
			ft_dup2(last_fd, STDIN_FILENO);
			ft_close(last_fd);
		}
	}
	if (node->cmd_num == -1 && node->out_fd != STDOUT_FILENO)
	{
		ft_dup2(node->out_fd, STDOUT_FILENO);
		ft_close(node->out_fd);
	}
}

//* if N > 1,  cmd = 0  means first process			  1   2
//*            cmd > 0  means middle process          3   2
//*            cmd = -1 means last process            3   4
void	child_dup2_close(t_cmd *node, int fd[2], int last_fd)
{
	node->in_fd = redirect_input(node->redirect);
	node->out_fd = redirect_output(node->redirect);
	if (node->cmd_num == 0 && node->in_fd != -1)
	{
		ft_dup2(node->in_fd, STDIN_FILENO);
		ft_close(node->in_fd);
	}
	if (node->cmd_num >= 0)
	{
		if (node->out_fd != STDOUT_FILENO)
		{
			ft_dup2(node->out_fd, STDOUT_FILENO);
			ft_close(node->out_fd);
			ft_close(fd[1]);
			ft_close(fd[0]);
		}
		else
		{
			ft_dup2(fd[1], STDOUT_FILENO);
			ft_close(fd[1]);
			ft_close(fd[0]);
		}
	}
	child_dup2_close_continue(node, fd, last_fd);
}

void	parent_close(int fd[2], int *last_fd, int cmd)
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
