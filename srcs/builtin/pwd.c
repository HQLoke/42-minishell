/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:18:00 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getcwd(char *buf, size_t size)
{
	char	*cwd;

	cwd = getcwd(buf, size);
	if (cwd == NULL)
	{
		ft_putstr_fd("pwd: ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	return (cwd);
}

void	builtin_pwd(t_cmd *node)
{
	char	*dir;

	dir = ft_getcwd(NULL, 0);
	if (dir == NULL)
	{
		g_environ->exit_status = EXIT_FAILURE;
		if (node->cmd_num == -2)
			return ;
		exit (EXIT_FAILURE);
	}
	ft_putstr_fd(dir, node->out_fd);
	ft_putstr_fd("\n", node->out_fd);
	free(dir);
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
