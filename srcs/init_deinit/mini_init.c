/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:06:07 by hloke             #+#    #+#             */
/*   Updated: 2022/03/31 14:09:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Initialize at the start before reading input
void	mini_init(t_mini **mini)
{
	*mini = ft_calloc(1, sizeof(t_mini));
	env_init(&(*mini)->env_head);
	(*mini)->pwd = NULL;
}
