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

#include "../../include/minishell.h"

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

int	builtin_echo(char **cmd)
{
	bool	status;
	bool	n;
	int		i;

	(void)env;
	status = 1;
	n = 1;
	i = 1;
	while (cmd[i] != NULL)
	{
		if (process_flag(cmd[i], &n, &status) == 0)
		{
			printf("%s", cmd[i]);
			if (cmd[i + 1] != NULL)
				printf(" ");
		}
		i++;
	}
	if (n == 1)
		printf("\n");
	return (EXIT_SUCCESS);
}
