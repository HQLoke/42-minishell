/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:48:41 by hloke             #+#    #+#             */
/*   Updated: 2022/04/10 10:37:30 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* loop through all environment variables to find a match and delete
//* if found, free the pointer and move the last string to fill the spot
//* then reduce the g_environ->num_var by 1
//* returns 0 if successfully deleted an environment variable
//* else returns -1
int	ft_delenv(char *env_key)
{
	int		i;
	char	*tmp;
	int		len;
	int		last_idx;

	i = 0;
	tmp = ft_strjoin(env_key, "=");
	len = ft_strlen(tmp);
	last_idx = g_environ->num_var - 1;
	while (g_environ->env_var[i])
	{
		if (ft_strncmp(g_environ->env_var[i], tmp, len) == 0)
		{
			free (g_environ->env_var[i]);
			g_environ->env_var[i] = g_environ->env_var[last_idx];
			g_environ->env_var[last_idx] = NULL;
			g_environ->num_var -= 1;
			free (tmp);
			return (0);
		}
		i += 1;
	}
	free (tmp);
	return (-1);
}
