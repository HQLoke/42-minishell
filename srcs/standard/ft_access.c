/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:12:17 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 10:12:26 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_access(const char *filename, int mode)
{
	if (access(filename, mode) == -1)
	{
		ft_putstr_fd("ft_access: ", STDERR_FILENO);
		perror(filename);
		exit (EXIT_FAILURE);
	}
}
