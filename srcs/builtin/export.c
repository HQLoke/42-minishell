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

void	print_not_valid(char *cmd, char *str)
{
	printf("bash: %s: `%s': not a valid identifier\n", cmd, str);
	return ;
}

// Check whether the key value to be added is a possible value: Consists of alphabets, numbers, _, not only numbers
int	check_var_syntax(char *str)
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

static void    print_export(void)
{
	int	i;

	i = 0;
	while (g_environ->env_var[i])
	{
		printf("declare -x ");

			printf("=\"%s\"");
		printf("\n");
		i += 1;
	}
}

int	builtin_export(t_cmd *node)
{
	int	i;

	if (ft_array_size(node->cmd_args) < 2)
		print_export();
	i = 0;
	while (node->cmd_args[i])
	{
		if (!check_var_syntax(node->cmd_args[i]))
		{
			print_not_valid("export", node->cmd_args[i]);
			return (1);
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}
