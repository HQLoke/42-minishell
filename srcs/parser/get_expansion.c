/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:06:00 by hloke             #+#    #+#             */
/*   Updated: 2022/04/10 22:15:58 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_expand(char *content, t_list **expansion, bool expand, int i)
{
	if (expand == 1)
	{
		
	}	
}

void	get_expansion(char *content, t_list **expansion)
{
	int		i;
	bool	expand;
	bool	dq;

	i = 0;
	expand = true;
	dq = false;
	while (content[i])
	{
		if (content[i] == '\"')
			dq = !dq;
		if (content[i] == '\'' && dq == false)
			expand = !expand;
		if (content[i] == '$')
			i += add_expand(content, expansion, expand, i);
		else
			i += 1;
	}
}
