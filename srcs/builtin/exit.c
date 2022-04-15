/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:22 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:42 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Prints exit and error message. 
	minishell is closed and the exit code and terminates it.
*/
void	builtin_exit(t_cmd *node)
{
	int	status;

	status = ft_array_size(node->cmd_args);
	if (status == 1)
	{
		ft_putendl_fd("exit", 1);
		exit (EXIT_SUCCESS);
	}
	if (status > 2)
	{
		ft_putendl_fd("exit\nbash: exit: too many arguments", STDERR_FILENO);
		g_environ->exit_status = EXIT_FAILURE;
		return ;
	}
	if (ft_atoi(node->cmd_args[1]) == 0)
	{
		ft_putstr_fd("exit\nbash: exit: ", 2);
		ft_putstr_fd(node->cmd_args[1], 2);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit (255);
	}
	ft_putstr_fd("exit\n", 1);
	exit (ft_atoi(node->cmd_args[1]));
}
