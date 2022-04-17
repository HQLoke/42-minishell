/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:42:42 by hloke             #+#    #+#             */
/*   Updated: 2022/04/17 11:43:59 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	return_or_exit(t_cmd *node, int exit_code)
{
	g_environ->exit_status = exit_code;
	if (node->cmd_num == -2)
		return ;
	exit (exit_code);
}
