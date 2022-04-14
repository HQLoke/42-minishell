/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:26:47 by hloke             #+#    #+#             */
/*   Updated: 2022/04/12 11:26:47 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_builtin(t_cmd *node)
{
	if (!ft_strncmp(node->cmd_args[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(node->cmd_args[0], "echo", 5))
		return (2);
	else if (!ft_strncmp(node->cmd_args[0], "env", 4))
		return (3);
	else if (!ft_strncmp(node->cmd_args[0], "exit", 5))
		return (4);
	else if (!ft_strncmp(node->cmd_args[0], "export", 7))
		return (5);
	else if (!ft_strncmp(node->cmd_args[0], "pwd", 4))
		return (6);
	else if (!ft_strncmp(node->cmd_args[0], "unset", 6))
		return (7);
	else
		return (-1);
}

//* returns 0 if no builtin is used
//* else returns 1
int	builtin_exec(t_cmd *node)
{
	int	ret;

	ret = check_builtin(node);
	if (ret == -1)
		return (0);
	g_environ->exit_status = EXIT_SUCCESS;
	if (ret == 1)
		builtin_cd(node);
	else if (ret == 2)
		builtin_echo(node);
	else if (ret == 3)
		builtin_env(node);
	else if (ret == 4)
		builtin_exit(node);
	else if (ret == 5)
		builtin_export(node);
	else if (ret == 6)
		builtin_pwd(node);
	else if (ret == 7)
		builtin_unset(node);
	return (1);
}
