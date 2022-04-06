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

static void	child_dup2_close_continue(t_mini *mini, int last_fd, int cmd)
{
	if (cmd == -1)
	{
		if (mini->in_fd != -1)
			input_dup2_close(2, mini->in_fd, last_fd);
		else
			input_dup2_close(1, last_fd);
		if (mini->out_fd != -1)
			output_dup2_close(1, mini->out_fd);
	}
	else if (cmd == -2)
	{
		if (mini->in_fd != -1)
			input_dup2_close(1, mini->in_fd);
		if (mini->out_fd != -1)
			output_dup2_close(1, mini->out_fd);
	}
}

//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	child_dup2_close(t_mini *mini, int fd[2], int last_fd, int cmd)
{
	mini->in_fd = redirect_input(mini->redirect);
	mini->out_fd = redirect_output(mini->redirect);
	if (cmd == 0)
	{
		if (mini->in_fd != -1)
			input_dup2_close(1, mini->in_fd);
		if (mini->out_fd != -1)
			output_dup2_close(3, mini->out_fd, fd[1], fd[0]);
		else
			output_dup2_close(2, fd[1], fd[0]);
	}
	else if (cmd > 0)
	{
		if (mini->in_fd != -1)
			input_dup2_close(2, mini->in_fd, last_fd);
		else
			input_dup2_close(1, last_fd);
		if (mini->out_fd != -1)
			output_dup2_close(3, mini->out_fd, fd[1], fd[0]);
		else
			output_dup2_close(2, fd[1], fd[0]);
	}
	child_dup2_close_continue(mini, last_fd, cmd);
}
