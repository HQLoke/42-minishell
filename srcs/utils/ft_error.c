/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:12:02 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 10:56:00 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Used only in the error_check in the first part
//* Set the exit to FAILURE to prevent executing process_line
void	ft_error(const char *str, int fd, int *exit)
{
	ft_putstr_fd((char *)str, fd);
	*exit = FAILURE;
}
