/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:47:53 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 17:18:23 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Check whether environment variable is in the linked list
char	*env_get_value(t_env *head, char *env_var)
{
	t_env	*tmp;
	int		len;

	tmp = head;
	len = ft_strlen(env_var);
	while (tmp)
	{
		if (ft_strncmp(tmp->env_var, env_var, len + 1) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (ft_calloc(1, sizeof(char)));
}

char	*ft_getenv(char *env_key)
{
	int	i;

	i = 0;
	while (g_environ->env_var[i])
	{
		
		i += 1;
	}
	return (NULL);
}
