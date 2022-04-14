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

static void	print_export(void)
{
	int		i;
	int		equal;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (g_environ->env_var[i])
	{
		equal = 0;
		while (g_environ->env_var[i][equal] != '=')
			equal += 1;
		tmp1 = ft_substr(g_environ->env_var[i], 0, equal);
		tmp2 = ft_substr(g_environ->env_var[i], equal + 1,
				ft_strlen(g_environ->env_var[i]) - equal - 1);
		printf("declare -x ");
		printf("%s=\"%s\"\n", tmp1, tmp2);
		free (tmp1);
		free (tmp2);
		i += 1;
	}
}

void	builtin_export(t_cmd *node)
{
	int	i;

	if (ft_array_size(node->cmd_args) < 2)
		print_export();
	i = 1;
	while (node->cmd_args[i] != NULL)
	{
		if (check_var_syntax(node->cmd_args[i]) == -1)
		{
			printf("bash: export `%s': not a valid identifier\n",
				node->cmd_args[i]);
			g_environ->exit_status = EXIT_FAILURE;
		}
		else
			ft_putenv(node->cmd_args[i]);
		i += 1;
	}
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
