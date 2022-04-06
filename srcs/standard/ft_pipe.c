/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:23:07 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 12:23:19 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("ft_pipe: ", STDERR_FILENO);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
}
