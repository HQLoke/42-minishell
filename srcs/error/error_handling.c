/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:02:59 by hloke             #+#    #+#             */
/*   Updated: 2022/03/23 15:20:43 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_handling(const char *input)
{
	int	exit;

	exit = success;
	check_ends(input, &exit);
	while (*input && exit == success)
	{
		if (*input == '\'' || *input == '\"')
			input += check_quotes(input, &exit);
		else if (*input == '|')
			input += check_pipe(input, &exit);
		else if (*input == '<' || *input == '>')
			input += check_redirection(input, &exit);
		else
			input += 1;
	}
	return (exit);
}
