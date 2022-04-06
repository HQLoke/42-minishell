/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:56:12 by hloke             #+#    #+#             */
/*   Updated: 2022/03/24 10:19:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Too many useless environment variables in original bash
//* Take those that we use in our minishell project only
//* Return the length of the environment variable without equal sign
static int	choose_env(char **env, const char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		if (ft_strncmp(str, env[i], len) == 0)
			return (len - 1);
		i += 1;
	}
	return (-1);
}

//* Initialize environment variables from original bash
//* For example: PWD=/Users/hloke/42-Core/9_minishell/test
//* tmp1 keeps the environment variable: PWD
//* tmp2 keeps the value: /Users/hloke/42-Core/9_minishell/test
void	env_init(t_env **head)
{
	int		ret;
	char	**env;
	char	*tmp1;
	char	*tmp2;

	ret = -1;
	env = ft_split("SHELL=?PWD=?OLDPWD=?HOME=?PATH=?USER=", '?');
	while (*environ)
	{
		ret = choose_env(env, *environ);
		if (ret != -1)
		{
			tmp1 = ft_substr(*environ, 0, ret);
			tmp2 = ft_substr(*environ, ret + 1, ft_strlen(*environ));
			env_set_value(head, tmp1, tmp2);
			free(tmp1);
			free(tmp2);
		}
		environ += 1;
	}
	ft_memdel((void **)env);
}
