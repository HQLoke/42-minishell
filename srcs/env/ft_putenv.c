/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:48:09 by hloke             #+#    #+#             */
/*   Updated: 2022/04/18 08:40:54 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* returns the index value of equal sign
static int	equal_index(char *env_var)
{
	int	index;

	index = 0;
	while (env_var[index] != '\0' && env_var[index] != '=')
		index += 1;
	return (index);
}

//* env_var is of the form name=value
//* index value plus one to include equal in the string
//* first loop through all environment variables to find a match
//* if found, replace the pointer with a new string
//* if not, realloc and add a new string at the end
//* returns 0 if successfully changed/added env_var
int	ft_putenv(char *env_var)
{
	int		i;
	int		index;
	char	**tmp;

	i = 0;
	index = equal_index(env_var);
	while (g_environ->env_var[i])
	{
		if (ft_strncmp(g_environ->env_var[i], env_var, index) == 0)
		{
			free (g_environ->env_var[i]);
			g_environ->env_var[i] = ft_strdup(env_var);
			return (0);
		}
		i += 1;
	}
	g_environ->num_var += 1;
	tmp = ft_array_dup(g_environ->env_var, g_environ->num_var);
	ft_memdel((void **)g_environ->env_var);
	g_environ->env_var = tmp;
	g_environ->env_var[i] = ft_strdup(env_var);
	return (0);
}
