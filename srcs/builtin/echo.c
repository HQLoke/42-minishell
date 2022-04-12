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

/* 
	Supports -n; Check if the -n option is the same.
    i++ which iterates through the av. 
    is_n is used to check if a final newline is needed. 
*/
bool	process_flag(const char *cmd, bool *n, bool *status)
{
	int	i;

	if (*status == 0)
		return (0);
	if (cmd[0] != '-' || (cmd[0] == '-' && cmd[1] == '\0'))
	{
		*status = 0;
		return (0);
	}
	i = 1;
	while (cmd[i] == 'n')
		++i;
	if (cmd[i] == '\0')
	{
		*n = 0;
		return (1);
	}
	*status = 0;
	return (0);
}

void	builtin_echo(t_cmd *node)
{
	bool	status;
	bool	n;
	int		i;

	status = 1;
	n = 1;
	i = 1;
	while (node->cmd_args[i] != NULL)
	{
		if (process_flag(node->cmd_args[i], &n, &status) == 0)
		{
			printf("%s", node->cmd_args[i]);
			if (node->cmd_args[i + 1] != NULL)
				printf(" ");
		}
		i += 1;
	}
	if (n == 1)
		printf("\n");
	if (node->cmd_num == -2)
	{
		g_environ->exit_status = EXIT_SUCCESS;
		return ;
	}
	exit (EXIT_SUCCESS);
}
