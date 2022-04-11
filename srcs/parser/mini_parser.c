/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:52:14 by hloke             #+#    #+#             */
/*   Updated: 2022/04/11 10:54:33 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_parser(t_list *token_head)
{
	t_list	*token_tmp;
	t_list	*expansion;

	token_tmp = token_head;
	expansion = NULL;
	while (token_tmp)
	{
		get_expansion(token_tmp->content, &expansion);
		trim_token(token_tmp->content);
		expand_token(token_tmp, expansion);
		if (token_tmp->type == command)
			expand_cmd(token_tmp);
		ft_lstclear(&expansion, free);
		token_tmp = token_tmp->next;
	}
}
