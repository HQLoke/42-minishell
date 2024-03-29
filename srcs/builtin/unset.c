/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:33 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:18:13 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_var_syntax(char *str)
{
	if (!ft_isalpha((int)str[0]) && str[0] != '_')
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (0);
		if (str[0] == '+' && str[1] == '=')
			return (0);
		if (!ft_isalpha((int)*str) && !ft_isdigit((int)*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

void	builtin_unset(t_cmd *node)
{
	int		i;

	i = 1;
	while (node->cmd_args[i] != NULL)
	{
		if (check_var_syntax(node->cmd_args[i]) != 1)
		{
			g_environ->exit_status = EXIT_FAILURE;
			ft_putstr_fd("bash: unset '", STDERR_FILENO);
			ft_putstr_fd(node->cmd_args[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		else
			ft_delenv(node->cmd_args[i]);
		i += 1;
	}
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
