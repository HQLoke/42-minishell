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

#include "minishell.h"

/* Haven't solved the problem of output redirection
Might have to use ft_putstr_fd instead of printf */
int	builtin_env(void)
{
	int	i;

	i = 0;
	while (g_environ->env_var[i] != NULL)
	{
		printf("%s\n", g_environ->env_var[i]);
		i += 1;
	}
	return (0);
}
