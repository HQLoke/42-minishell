/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:27 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:56 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* check whether the key value to be added is a possible value: 
//* consists of alphabets, numbers, _, not only numbers
static int	check_var_syntax(char *str)
{
	if (!ft_isalpha((int)str[0]) && str[0] != '_')
		return (0);
	while (*str)
	{
		if (*str == '=')
			return (1);
		if (str[0] == '+' && str[1] == '=')
			return (2);
		if (!ft_isalpha((int)*str) && !ft_isdigit((int)*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

static void	print_export(t_cmd *node)
{
	int		equal;
	char	*tmp1;
	char	**g_tmp;

	g_tmp = g_environ->env_var;
	while (*g_tmp)
	{
		equal = 0;
		while ((*g_tmp)[equal] != '\0' && (*g_tmp)[equal] != '=')
			equal += 1;
		tmp1 = ft_substr((*g_tmp), 0, equal);
		ft_putstr_fd("declare -x ", node->out_fd);
		ft_putstr_fd(tmp1, node->out_fd);
		if (ft_getenv(tmp1) != NULL)
		{
			ft_putstr_fd("=\"", node->out_fd);
			ft_putstr_fd(ft_getenv(tmp1), node->out_fd);
			ft_putstr_fd("\"", node->out_fd);
		}
		ft_putstr_fd("\n", node->out_fd);
		free (tmp1);
		g_tmp += 1;
	}
}

void	builtin_export(t_cmd *node)
{
	int		i;
	bool	error;

	if (ft_array_size(node->cmd_args) < 2)
		print_export(node);
	i = 1;
	error = false;
	while (node->cmd_args[i] != NULL)
	{
		if (check_var_syntax(node->cmd_args[i]) != 1)
		{
			error = true;
			ft_putstr_fd("bash: export '", STDERR_FILENO);
			ft_putstr_fd(node->cmd_args[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		else
			ft_putenv(node->cmd_args[i]);
		i += 1;
	}
	return (return_or_exit(node, error));
}
