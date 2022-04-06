/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:03:35 by ktiong            #+#    #+#             */
/*   Updated: 2022/04/04 14:46:32 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * argv_len() - return the number of argument in a NULL terminated array
 * @argv:       NULL terminated array of argument strings
 *
 * Return: the number of element in @argv, excluding NULL termination
 */
int	argv_len(char *argv[])
{
	int	len;

	len = 0;
	while (argv[len] != NULL)
		len++;
	return (len);
}
