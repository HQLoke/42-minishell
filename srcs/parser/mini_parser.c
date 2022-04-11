/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:52:14 by hloke             #+#    #+#             */
/*   Updated: 2022/04/11 14:43:25 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Number of commands is pipe_count + 1
void	mini_parser(t_list *token_head, t_cmd **command_head)
{
	t_list	*token_tmp;
	t_list	*expansion;
	int		pipe_count;

	token_tmp = token_head;
	expansion = NULL;
	pipe_count = 0;
	while (token_tmp)
	{
		if (token_tmp->type == piping)
			pipe_count += 1;
		get_expansion(token_tmp->content, &expansion);
		trim_token(token_tmp->content);
		expand_token(token_tmp, expansion);
		ft_lstclear(&expansion, free);
		token_tmp = token_tmp->next;
	}
	make_cmd_list(token_head, command_head, pipe_count + 1);
}
