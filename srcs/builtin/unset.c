/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:33 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:18:13 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_cmd *node)
{
	int		i;

	i = 0;
	while (node->cmd_args[i] != NULL)
	{
		if (check_var_syntax(node->cmd_args[i]) == -1)
		{
			print_not_valid("unset", node->cmd_args[i]);
			return (-1);
		}
		i += 1;
	}
	return (0);
}
