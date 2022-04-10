/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:47:53 by hloke             #+#    #+#             */
/*   Updated: 2022/04/10 10:26:48 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* returns a pointer to the environment value if environment key is valid
//* else returns NULL
char	*ft_getenv(char *env_key)
{
	int		i;
	char	*tmp;
	int		index;

	i = 0;
	tmp = ft_strjoin(env_key, "=");
	index = ft_strlen(tmp);
	while (g_environ->env_var[i])
	{
		if (ft_strncmp(g_environ->env_var[i], tmp, index) == 0)
		{
			free (tmp);
			return (g_environ->env_var[i] + index);
		}
		i += 1;
	}
	free (tmp);
	return (NULL);
}
