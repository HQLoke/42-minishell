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

int	builtin_unset(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[++i] != NULL)
	{
		if (check_var_syntax(cmd[i]) == -1)
		{
			print_not_valid("unset", cmd[i++]);
			return (-1);
		}
		
	}
	return (0);
}
