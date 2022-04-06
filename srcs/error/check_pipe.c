/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:55 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 11:47:22 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Check if the pipeline is empty
//* For example: echo "hello world" | | cat -e will set exit to FAILURE
int	check_pipe(const char *str, int *exit)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '|')
		{
			ft_error("Syntax error: empty pipe\n", STDERR_FILENO, exit);
			return (1);
		}
		else if (str[i] == ' ')
			i += 1;
		else
			return (1);
	}
	return (1);
}
