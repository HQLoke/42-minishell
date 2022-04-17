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

void	builtin_env(t_cmd *node)
{
	int	i;

	if (ft_array_size(node->cmd_args) > 1)
	{
		ft_putstr_fd("env: no such file or directory\n", STDERR_FILENO);
		return (return_or_exit(node, 127));
	}
	i = 0;
	while (g_environ->env_var[i] != NULL)
	{
		ft_putstr_fd(g_environ->env_var[i], node->out_fd);
		ft_putstr_fd("\n", node->out_fd);
		i += 1;
	}
	return (return_or_exit(node, EXIT_SUCCESS));
}
