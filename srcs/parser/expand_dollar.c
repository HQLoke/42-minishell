/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:16:12 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 18:16:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* For example: Hello$World will substr into Hello & World
//* Then join with env_value in the middle
//* Final str would be HelloEnvironmentVariableWorld
static void	replace_dollar(char **str, char *env_value, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(*str, 0, *i);
	tmp2 = ft_substr(*str, *i + 1, ft_strlen(*str) - (*i + 1));
	tmp3 = ft_strjoin(tmp, env_value);
	free(tmp);
	tmp = ft_strjoin(tmp3, tmp2);
	free(tmp2);
	free(tmp3);
	free(*str);
	*str = tmp;
	*i += ft_strlen(env_value);
}

//* Look for each $ sign to expand from the expansion linked list
//* Be careful of zero length content
void	expand_dollar(char **cmd_args, t_list *expansion)
{
	int		i;
	t_list	*tmp;

	tmp = expansion;
	while (*cmd_args)
	{
		i = 0;
		while ((*cmd_args)[i] != '\0')
		{
			if ((*cmd_args)[i] == '$')
			{
				if (tmp->type == 0)
					i += 1;
				else
					replace_dollar(cmd_args, tmp->content, &i);
				tmp = tmp->next;
			}
			else
				i += 1;
		}
		cmd_args += 1;
	}
}
