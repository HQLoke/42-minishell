/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:02:02 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 15:55:28 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirection(const char *str, int *exit)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i - 1] == '<' && str[i] == '<')
			return (1);
		else if (str[i - 1] == '>' && str[i] == '>')
			return (1);
		else if (str[i] == ' ')
			i += 1;
		else if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		{
			ft_error("Syntax error: redirection error\n", STDERR_FILENO, exit);
			return (1);
		}
		else
			return (1);
	}
	if (str[i] == '\0')
		ft_error("Syntax error: redirection error\n", STDERR_FILENO, exit);
	return (1);
}
