/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_deinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:08:02 by hloke             #+#    #+#             */
/*   Updated: 2022/03/31 15:33:16 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_deinit(t_env **head)
{
	t_env	*ptr;

	while (*head)
	{
		ptr = (*head)->next;
		free ((*head)->env_var);
		free ((*head)->value);
		free ((*head));
		*head = ptr;
	}
	*head = NULL;
}
