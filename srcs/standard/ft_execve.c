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

//* check if PATH variable is empty or not
//* if not empty, returns an array of ft_strjoined cmds, else return NULL
static char	**joined_cmd(char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**arr;

	if (ft_getenv("PATH") == NULL)
		return (NULL);
	else
		arr = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (arr[i])
	{
		tmp2 = ft_strjoin(arr[i], tmp);
		free (arr[i]);
		arr[i] = tmp2;
		i += 1;
	}
	free (tmp);
	return (arr);
}

//* Execute non-builtin functions only
//* Handles Relative & Absolute first, then PATH
void	ft_execve(char **cmd_args)
{
	int		i;
	char	**path;

	i = 0;
	execve(cmd_args[0], cmd_args, g_environ->env_var);
	path = joined_cmd(cmd_args[0]);
	if (path != NULL)
	{
		while (path[i])
		{
			execve(path[i], cmd_args, g_environ->env_var);
			i += 1;
		}
	}
	ft_memdel((void **)path);
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (EXIT_FAILURE);
}
