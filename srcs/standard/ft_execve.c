/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:12:32 by hloke             #+#    #+#             */
/*   Updated: 2022/03/28 10:57:50 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Execute non-builtin functions only
//* Handles Relative & Absolute first, then PATH
void	ft_execve(char **cmd_args, char **path)
{
	int		i;
	char	*tmp;
	char	*cmd;

	i = 0;
	if (execve(cmd_args[0], cmd_args, path) == -1)
	{
		while (path[i])
		{
			tmp = ft_strjoin(path[i], "/");
			cmd = ft_strjoin(tmp, cmd_args[0]);
			if (execve(cmd, cmd_args, path) == -1)
			{
				free (tmp);
				free (cmd);
			}
			i += 1;
		}
	}
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (EXIT_FAILURE);
}
