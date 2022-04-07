/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:33:43 by hloke             #+#    #+#             */
/*   Updated: 2022/04/07 17:13:20 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_exit(char *error_msg)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
