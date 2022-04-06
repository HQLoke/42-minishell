/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:16 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:37:01 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Haven't solved the problem of output redirection
Might have to use ft_putstr_fd instead of printf */

int	builtin_env(char **cmd, t_env *env)
{
	(void)cmd;
	while (env)
	{
		if (env->value != NULL)
			printf("%s=%s\n", env->env_var, env->value);
		env = env->next;
	}
	return (0);
}
