/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:58:23 by hloke             #+#    #+#             */
/*   Updated: 2022/04/11 16:35:57 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_exit_status(void)
{
	int		status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_environ->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_environ->exit_status = 128 + WTERMSIG(status);
		else
			g_environ->exit_status = status;
	}
}
