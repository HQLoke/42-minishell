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

//* Return the index value of the equal sign
static int	equal_index(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i += 1;
	}
	ft_putstr_fd("equal index failure\n", 2);
	exit (EXIT_FAILURE);
}

//* Initialize environment variables from original bash
//* For example: PWD=/Users/hloke/42-Core/9_minishell/test
//* tmp1 keeps the environment variable: PWD
//* tmp2 keeps the value: /Users/hloke/42-Core/9_minishell/test
void	env_init(t_env **head, char **envp)
{
	int		ret;
	char	*tmp1;
	char	*tmp2;

	ret = -1;
	while (*envp)
	{
		ret = equal_index(*envp);
		tmp1 = ft_substr(*envp, 0, ret);
		tmp2 = ft_substr(*envp, ret + 1, ft_strlen(*envp));
		env_set_value(head, tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		envp += 1;
	}
}
