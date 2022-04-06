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

void		builtin_env(char **cmd, t_env	*env)
{
	t_env	*cpy;

	cpy = env;
	while (cpy)
	{
		printf("%s=%s\n", cpy->env_var, cpy->value);
		cpy = cpy->next;
	}
}
