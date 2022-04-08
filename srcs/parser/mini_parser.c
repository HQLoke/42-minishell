/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:52:14 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 16:29:16 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_parser(t_list *token_head)
{
	t_list	*token_tmp;

	token_tmp = token_head;
	while (token_tmp)
	{
		expand_token(token_tmp);
		token_tmp = token_tmp->next;
	}
}
