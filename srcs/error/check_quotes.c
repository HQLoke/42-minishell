/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:40:45 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 10:52:39 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(const char *str, int *exit)
{
	int	i;

	i = 1;
	if (*str == '\'')
	{
		while (str[i] && str[i] != '\'')
			i += 1;
	}
	else if (*str == '\"')
	{
		while (str[i] && str[i] != '\"')
			i += 1;
	}
	if (str[i] == '\0')
	{
		ft_error("Syntax error: unclosed quotes\n", STDERR_FILENO, exit);
		return (i);
	}
	return (i + 1);
}
