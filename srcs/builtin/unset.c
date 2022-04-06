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

#include "../../include/minishell.h"

static void	delete_element(t_env *env)
{
	free(env->env_var);
	free(env->value);
	free(env);
}

static t_env	*remove_unset(t_env *del, t_env *env)
{
	t_env	*tmp;
	t_env	*next;

	{	if (env == del)

		tmp = env->next;
		delete_element(env);
		return (tmp);
	}
	tmp = env;
	while (tmp)
	{
		if (tmp->next && (ft_strncmp(tmp->next->env_var, del->env_var, get_arglen(tmp->next->env_var, del->env_var)) == 0))
		{
			next = tmp->next;
			tmp->next = tmp->next->next;
			delete_element(next);
			return (env);
		}
		tmp = tmp->next;
	}
	return (env);
}

int	builtin_unset(char **cmd, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (cmd[++i] != NULL)
	{
		if (check_var_syntax(cmd[i]) == -1)
		{
			print_not_valid("unset", cmd[i++]);
			return (-1);
		}
		tmp = env;
		while (tmp != NULL)
		{
			if (strcmp(tmp->env_var, cmd[i]) == 0)
			{
				env = remove_unset(tmp, env);
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}
