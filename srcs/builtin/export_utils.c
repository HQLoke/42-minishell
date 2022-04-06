/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:18:04 by ktiong            #+#    #+#             */
/*   Updated: 2022/04/04 23:19:17 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_arglen(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

char	*add_front(int fd, char *value, char s)
{
	char	*temp;
	char	*new;

	temp = malloc(sizeof(char) * 2);
	temp[0] = s;
	temp[1] = '\0';
	new = ft_strjoin (temp, value);
	free(temp);
	free(value);
	return (new);
}

char	*add_end(int fd, char *value, char c)
{
	char	*temp;
	char	*new;

	temp = malloc(sizeof(char) * 2);
	temp[0] = c;
	temp[1] = '\0';
	new = ft_strjoin(value, temp);
	free(temp);
	free(value);
	return (new);
}

void	fill_list(t_env *env, char argv)
{
	if (argv == '=')
	{
		env->value = add_front(1, env->value, '"');
		env->value = add_end(1, env->value, '"');
		env->value = ft_strjoin("=", env->value);
		free(env->value);
	}
}

int	check_list(t_env *env, t_env *new_env, char *argv, int i)
{
	if (!ft_strncmp(env->env_var, new_env->env_var, get_arglen(env->env_var, new_env->env_var)))
	{
		if (argv[i] == '=')
		{
			new_env->value = add_front(1, new_env->value, '"');
			new_env->value = add_end(1, new_env->value, '"');
			env->value = new_env->value;
			return (1);
		}
		else
			return (1);
	}
	else
		return (0);
}
