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

void	builtin_pwd(t_cmd *node)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (dir == NULL)
	{
		printf("cd: %s\n", strerror(errno));
		return ;
	}
	printf("%s\n", dir);
	free(dir);
	if (node->cmd_num == -2)
	{
		g_environ->exit_status = EXIT_SUCCESS;
		return ;
	}
	exit (EXIT_SUCCESS);
}
