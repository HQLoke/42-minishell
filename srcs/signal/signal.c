/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:36:29 by ktiong            #+#    #+#             */
/*   Updated: 2022/03/27 16:37:44 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigquit_handler(void)
{
	ft_putstr_fd("\033[2D\n", 1);
	exit (1);
}

static void	signal_handler(int i)
{
	pid_t 	pid;
	int		status;

	pid = waitpid(-1, &status, 1);
	if (i == SIGINT)
	{
		if (pid == -1)
		{
			// rl_on_new_line();
			// rl_redisplay();
			ft_putstr_fd("\n", 2);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (i == SIGQUIT)
	{
		if (pid == -1)
		{
			rl_on_new_line();
			rl_redisplay();
			printf("\b\b%c%c\n", 0x7f, 0x7f);
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	ft_signal(void)
{
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
}
