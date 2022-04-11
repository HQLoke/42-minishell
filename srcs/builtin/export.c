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

#include "../../include/minishell.h"

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
		if (!ft_isalpha((int)*str) && \
			!ft_isdigit((int)*str) && \
			*str != '_')
			return (0);
		str++;
	}
	return (1);
}

static void    print_export(void)
{
	while ()
	{
		printf("declare -x ");

			printf("=\"%s\"");
		printf("\n");

	}
	exit (0);
}

static int	export_set(char *argv)
{
	int		i;
	t_env	*new_env;

	i = 0;
	new_env = malloc(sizeof(t_env));
	while (argv[i] && argv[i] != '=')
		i++;
	new_env->env_var = ft_substr(argv, 0, i);
	new_env->value = ft_substr(argv, i + 1, ft_strlen(argv));
	if (new_env->value == NULL && argv[i] == '=')
		new_env->value = ft_strdup("");
	while (env->next != NULL)
	{
		if (check_list(env, new_env, argv, i))
			return (0);
		else
			env = env->next;
	}
	if (check_list(env, new_env, argv, i))
		return (0);
	fill_list(new_env, argv[i]);
	env->next = new_env;
	new_env->next = NULL;
	return (0);
}

int	builtin_export(char **cmd, t_env *env)
{
	int	i;

	i = 0;

	if (ft_array_size(cmd) < 2)
		print_export(env);
	if (cmd[1])
	{
		while (cmd[++i])
		{
			if (!check_var_syntax(cmd[i]))
			{
				print_not_valid("export", cmd[i++]);
				return (1);
			}
			else
				export_set(env, cmd[i]);
		}
	}
	return (EXIT_SUCCESS);
}
