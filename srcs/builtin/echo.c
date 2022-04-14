/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:13 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:34 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_cmd *node)
{
	int		i;

	i = 1;
	while (node->cmd_args[i] != NULL)
	{
		printf("%s", node->cmd_args[i]);
		if (node->cmd_args[i + 1] != NULL)
			printf(" ");
		i += 1;
	}
	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
