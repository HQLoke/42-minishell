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

static int	replace_dollar(t_list *node, int i)
{
	int		len;
	char	*tmp;

	len = 0;
	while (ft_strchr("\0 \'\"$", node->content[i + 1 + len]) == NULL)
		len += 1;
	if (len == 0)
		return (1);
	tmp = ft_substr(node->content, i + 1, len);
}

void	expand_token(t_list *node)
{
	bool	single_q;
	int		i;

	single_q = false;
	i = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\'')
			single_q = !single_q;
		if (node->content[i] == '$' && single_q == false)
			i += replace_dollar(node, i);
		else
			i += 1;
	}
}
