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

//* prints out all arguments
//* first is to check space between arguments
void	builtin_echo(t_cmd *node)
{
	int		i;
	bool	first;

	i = 1;
	first = true;
	if (check_option(node->cmd_args[1]) == 1)
		i = 2;
	while (node->cmd_args[i] != NULL)
	{
		if (ft_strlen(node->cmd_args[i]) != 0)
		{
			if (first == false)
				ft_putstr_fd(" ", node->out_fd);
			ft_putstr_fd(node->cmd_args[i], node->out_fd);
			first = false;
		}
		i += 1;
	}
	if (check_option(node->cmd_args[1]) != 1)
		ft_putstr_fd("\n", node->out_fd);
	return (return_or_exit(node, EXIT_SUCCESS));
}
