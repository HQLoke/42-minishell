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

//* returns 0 if NULL string or wrong option
//* else returns 1
static int	check_option(char *cmd)
{
	int	i;

	if (cmd == NULL)
		return (0);
	if (cmd[0] != '-')
		return (0);
	i = 1;
	while (cmd[i] == 'n')
		i += 1;
	if (cmd[i] == '\0')
		return (1);
	return (0);
}

void	builtin_echo(t_cmd *node)
{
	int		i;

	i = 1;
	if (check_option(node->cmd_args[1]) == 1)
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
	if (check_option(node->cmd_args[1]) != 1)
		ft_putstr_fd("\n", node->out_fd);
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
