/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_deinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:06:32 by hloke             #+#    #+#             */
/*   Updated: 2022/03/31 17:27:30 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Deinitialize at EXIT_FAILURE or at the end of program
void	mini_deinit(t_mini **mini)
{
	env_deinit(&(*mini)->env_head);
	free (*mini);
	*mini = NULL;
}
