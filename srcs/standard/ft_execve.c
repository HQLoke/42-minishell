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
void	ft_execve(char **cmd_args)
{
	int		i;
	char	*tmp;
	char	*cmd;
	char	**path;

	i = 0;
	path = ft_split(ft_getenv("PATH"), ':');
	if (execve(cmd_args[0], cmd_args, g_environ->env_var) == -1)
	{
		while (path[i++])
		{
			tmp = ft_strjoin(path[i], "/");
			cmd = ft_strjoin(tmp, cmd_args[0]);
			if (execve(cmd, cmd_args, g_environ->env_var) == -1)
			{
				free (tmp);
				free (cmd);
			}
		}
	}
	ft_memdel((void **)path);
	cmd_not_found(cmd_args[0]);
}
