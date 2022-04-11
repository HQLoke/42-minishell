/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:35 by ktiong            #+#    #+#             */
/*   Updated: 2022/03/22 20:16:57 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* returns 0 if no match is found
//* else returns 1
int	execute_builtin(t_cmd *node)
{
	if (!ft_strncmp(node->cmd_args[0], "cd", 3))
		builtin_cd(node);
	else if (!ft_strncmp(node->cmd_args[0], "echo", 5))
		builtin_echo(node);
	else if (!ft_strncmp(node->cmd_args[0], "env", 4))
		builtin_env(node);
	else if (!ft_strncmp(node->cmd_args[0], "exit", 5))
		builtin_exit(node);
	else if (!ft_strncmp(node->cmd_args[0], "export", 7))
		builtin_export(node);
	else if (!ft_strncmp(node->cmd_args[0], "pwd", 4))
		builtin_pwd(node);
	else if (!ft_strncmp(node->cmd_args[0], "unset", 6))
		builtin_unset(node);
	else
		return (0);
	return (1);
}
