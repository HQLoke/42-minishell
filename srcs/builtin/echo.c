/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:13 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:34 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_cmd *node)
{
	int		i;

	i = 1;
	if (node->cmd_args[1] && ft_strncmp(node->cmd_args[1], "-n", 3) == 0)
		i = 2;
	while (node->cmd_args[i] != NULL)
	{
		if (ft_strlen(node->cmd_args[i]) == 0)
		{
			i += 1;
			continue ;
		}
		ft_putstr_fd(node->cmd_args[i], node->out_fd);
		if (node->cmd_args[i + 1] != NULL
			&& ft_strlen(node->cmd_args[i + 1]) != 0)
			ft_putstr_fd(" ", node->out_fd);
		i += 1;
	}
	if (node->cmd_args[1] && ft_strncmp(node->cmd_args[1], "-n", 3) != 0)
		ft_putstr_fd("\n", node->out_fd);
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
