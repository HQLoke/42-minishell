/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:26:51 by hloke             #+#    #+#             */
/*   Updated: 2022/04/07 15:43:38 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Assign token type to each node in the token_head linked list
void	assign_token(t_list **token_head)
{
	t_list	*tmp;

	tmp = *token_head;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "<<", 3) == 0)
			tmp->type = heredoc;
		else if (ft_strncmp(tmp->content, "<", 2) == 0)
			tmp->type = input;
		else if (ft_strncmp(tmp->content, ">>", 3) == 0)
			tmp->type = append;
		else if (ft_strncmp(tmp->content, ">", 2) == 0)
			tmp->type = trunc;
		else if (ft_strncmp(tmp->content, "|", 2) == 0)
			tmp->type = piping;
		else
			tmp->type = literal;
		tmp = tmp->next;
	}
}
