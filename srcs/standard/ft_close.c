/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:12:43 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 10:12:54 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr_fd("ft_close: ", STDERR_FILENO);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
}
