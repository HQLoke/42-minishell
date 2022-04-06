/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:10:58 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 10:11:14 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unlink(const char *pathname)
{
	if (unlink(pathname) == -1)
	{
		ft_putstr_fd("ft_unlink: ", STDERR_FILENO);
		perror(pathname);
		exit (EXIT_FAILURE);
	}
}
