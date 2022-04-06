/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:52:47 by hloke             #+#    #+#             */
/*   Updated: 2022/04/06 23:33:48 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_del_value(t_env **env_head, char *key)
{
	t_env	*env;
	t_env	*tmp;

	env = *env_head;
	while (env)
	{
		tmp = env->next;
		if (ft_strncmp(env->env_var, key, ft_strlen(key) + 1) == 0)
		{
			ft_free(env->env_var);
			ft_free(env->value);
			return ;
		}
		env = tmp;
	}
}
