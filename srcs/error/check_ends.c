/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:08:43 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 13:55:24 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_ending(const char *str, int *exit)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		if (str[len] == '|' || str[len] == '\\' || str[len] == ';')
		{
			ft_error("Syntax error: cannot end with '|', '\\' or ';'\n",
				STDERR_FILENO, exit);
			return ;
		}
		else if (str[len] == ' ')
			len -= 1;
		else
			return ;
	}
}

//* The beginning & ending of input cannot be '|' '\' ';'
int	check_ends(const char *str, int *exit)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '\\' || str[i] == ';')
		{
			ft_error("Syntax error: cannot begin with '|', '\\' or ';'\n",
				STDERR_FILENO, exit);
			return (1);
		}
		else if (str[i] == ' ')
			i += 1;
		else
			break ;
	}
	check_ending(str, exit);
	return (1);
}
