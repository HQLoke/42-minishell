/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:39:13 by hloke             #+#    #+#             */
/*   Updated: 2022/03/24 18:57:27 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Check whether environment variable is in the linked list
char	*env_get_value(t_env *head, char *env_var)
{
	t_env	*tmp;
	int		len;

	tmp = head;
	len = ft_strlen(env_var);
	while (tmp)
	{
		if (ft_strncmp(tmp->env_var, env_var, len + 1) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (ft_calloc(1, sizeof(char)));
}

int	update_env_value(t_env *env, char *tmp, char *env_var)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env_get_value(env, tmp))
		{
			free(env->value);
			env->value = ft_strdup(env_var);
			i = 1;
			break ;
		}
		env = env->next;
	}
	return (i);
}
