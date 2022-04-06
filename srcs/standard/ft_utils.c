/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:27:42 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 12:24:04 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("ft_kill: ", STDERR_FILENO);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
}
