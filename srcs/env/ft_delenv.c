/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:48:41 by hloke             #+#    #+#             */
/*   Updated: 2022/04/18 11:26:06 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* possible two cases: abc or abc=16
//* this function will return the correct len to compare
//* return 0 if env_key matches, else return 1
static int	correct_compare(char *env_key, char *g_env_var)
{
	int		i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(env_key);
	while (g_env_var[i] != '\0' && g_env_var[i] != '=')
		i += 1;
	if (g_env_var[i] == '\0')
	{
		if (len != ft_strlen(g_env_var))
			return (1);
		return (0);
	}
	tmp = ft_strjoin(env_key, "=");
	i = ft_strncmp(g_env_var, tmp, ft_strlen(tmp));
	free (tmp);
	return (i);
}

//* loop through all environment variables to find a match and delete
//* if found, free the pointer and move the last string to fill the spot
//* then reduce the g_environ->num_var by 1
//* returns 0 if successfully deleted an environment variable
//* else returns -1
int	ft_delenv(char *env_key)
{
	int		i;
	int		last_idx;

	i = 0;
	last_idx = g_environ->num_var - 1;
	while (g_environ->env_var[i])
	{
		if (correct_compare(env_key, g_environ->env_var[i]) == 0)
		{
			free (g_environ->env_var[i]);
			g_environ->env_var[i] = g_environ->env_var[last_idx];
			g_environ->env_var[last_idx] = NULL;
			g_environ->num_var -= 1;
			return (0);
		}
		i += 1;
	}
	return (-1);
}
