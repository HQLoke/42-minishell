/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:09:49 by hloke             #+#    #+#             */
/*   Updated: 2022/03/24 10:11:22 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_new_value(t_env **head, char *env_var, char *value)
{
	t_env	*new;
	t_env	*tmp;

	new = ft_calloc(1, sizeof(t_env));
	new->env_var = ft_strdup(env_var);
	new->value = ft_strdup(value);
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	env_set_value(t_env **head, char *env_var, char *value)
{
	t_env		*tmp;
	int			len;

	tmp = *head;
	len = ft_strlen(env_var);
	while (tmp)
	{
		if (ft_strncmp(tmp->env_var, env_var, len + 1) == 0)
		{
			if (tmp->value != NULL)
				free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	env_new_value(head, env_var, value);
}
