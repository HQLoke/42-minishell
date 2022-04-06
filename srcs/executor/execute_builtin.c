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

#include "../../include/minishell.h"

int	execute_builtin(t_mini *mini)
{
	if (!ft_strncmp(mini->cmd_args[0], "cd", 3))
		builtin_cd(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "echo", 5))
		builtin_echo(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "env", 4))
		builtin_env(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "pwd", 4))
		builtin_pwd(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "unset", 6))
		builtin_unset(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "export", 7))
		builtin_export(mini->cmd_args, mini->env_head);
	else if (!ft_strncmp(mini->cmd_args[0], "exit", 5))
		builtin_exit(mini->cmd_args, mini->env_head);
	else
		return (0);
	return (1);
}
