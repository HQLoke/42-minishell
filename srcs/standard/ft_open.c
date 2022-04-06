/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:35:56 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 11:36:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* If successful, return the file descriptor
//* Else exit with EXIT_FAILURE
int	ft_open(const char *path, int flag, int mode)
{
	int	file_des;

	file_des = open(path, flag, mode);
	if (file_des == -1)
	{
		ft_putstr_fd("ft_open: ", STDERR_FILENO);
		perror(path);
		exit (EXIT_FAILURE);
	}
	return (file_des);
}
