/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:16:12 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 18:16:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	replace_dollar(t_list *node, t_list *exp_tmp, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (exp_tmp->type == 0)
		return (1);
	if (exp_tmp->type == 1 && exp_tmp->content == NULL)
	{
		ft_memmove(node->content + i, node->content + i + 1,
			ft_strlen(node->content) - i);
		return (0);
	}
	tmp2 = ft_substr(node->content, 0, i);
	tmp3 = ft_substr(node->content, i + 1, ft_strlen(node->content) - (i + 1));
	tmp = ft_strjoin(tmp2, exp_tmp->content);
	free (tmp2);
	tmp2 = ft_strjoin(tmp, tmp3);
	free (tmp);
	free (tmp3);
	free (node->content);
	node->content = tmp2;
	return (ft_strlen(exp_tmp->content));
}

void	expand_token(t_list *node, t_list *expansion)
{
	int		i;
	t_list	*exp_tmp;

	i = 0;
	exp_tmp = expansion;
	while (node->content[i])
	{
		if (node->content[i] == '$')
		{
			i += replace_dollar(node, exp_tmp, i);
			exp_tmp = exp_tmp->next;
		}
		else
			i += 1;
	}
}
