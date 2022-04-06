/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:09:35 by hloke             #+#    #+#             */
/*   Updated: 2022/03/28 10:31:15 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	ft_waitpid(pid_t pid, int *wstatus, int options)
{
	pid_t	ret;

	ret = waitpid(pid, wstatus, options);
	if (ret == -1)
	{
		ft_putstr_fd("ft_waitpid: ", STDERR_FILENO);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
	return (ret);
}
