/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_dup2_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:25:59 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 12:40:22 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	input_dup2_close(int num_close, ...)
{
	va_list	list;
	int		i;

	va_start(list, num_close);
	i = va_arg(list, int);
	ft_dup2(i, STDIN_FILENO);
	ft_close(i);
	i = 1;
	while (i < num_close)
	{
		ft_close(va_arg(list, int));
		i += 1;
	}
	va_end(list);
}

static void	output_dup2_close(int num_close, ...)
{
	va_list	list;
	int		i;

	va_start(list, num_close);
	i = va_arg(list, int);
	ft_dup2(i, STDOUT_FILENO);
	ft_close(i);
	i = 1;
	while (i < num_close)
	{
		ft_close(va_arg(list, int));
		i += 1;
	}
	va_end(list);
}

static void	child_dup2_close_continue(t_cmd *node, int last_fd)
{
	if (node->cmd_num == -1)
	{
		if (node->in_fd != -1)
			input_dup2_close(2, node->in_fd, last_fd);
		else
			input_dup2_close(1, last_fd);
		if (node->out_fd != -1)
			output_dup2_close(1, node->out_fd);
	}
	else if (node->cmd_num == -2)
	{
		if (node->in_fd != -1)
			input_dup2_close(1, node->in_fd);
		if (node->out_fd != -1)
			output_dup2_close(1, node->out_fd);
	}
}

//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	child_dup2_close(t_cmd *node, int fd[2], int last_fd)
{
	node->in_fd = redirect_input(node->redirect);
	node->out_fd = redirect_output(node->redirect);
	if (node->cmd_num == 0)
	{
		if (node->in_fd != -1)
			input_dup2_close(1, node->in_fd);
		if (node->out_fd != -1)
			output_dup2_close(3, node->out_fd, fd[1], fd[0]);
		else
			output_dup2_close(2, fd[1], fd[0]);
	}
	else if (node->cmd_num > 0)
	{
		if (node->in_fd != -1)
			input_dup2_close(2, node->in_fd, last_fd);
		else
			input_dup2_close(1, last_fd);
		if (node->out_fd != -1)
			output_dup2_close(3, node->out_fd, fd[1], fd[0]);
		else
			output_dup2_close(2, fd[1], fd[0]);
	}
	child_dup2_close_continue(node, last_fd);
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
