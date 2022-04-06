/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:58:23 by hloke             #+#    #+#             */
/*   Updated: 2022/04/06 19:23:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_exit_status(t_mini *mini)
{
	int		status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			mini->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			mini->last_exit_status = 128 + WTERMSIG(status);
		else
			mini->last_exit_status = status;
	}
}
