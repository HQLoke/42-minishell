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

#include "../../include/minishell.h"

/*
	Prints exit and error message. 
	minishell is closed and the exit code and terminates it.
*/
int	builtin_exit(char **cmd, t_env *env)
{
	int	status;

	(void)env;
	status = 0;
	while (cmd[status] != NULL)
		++status;
	if (status == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(EXIT_SUCCESS);
	}
	if (status > 2)
	{
		ft_putendl_fd("bash: exit: too many arguments", 2);
		return (1);
	}
	if (ft_atoi(cmd[1]) == 0)
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	ft_putstr_fd("exit\n", 1);
	exit(ft_atoi(cmd[1]));
}
