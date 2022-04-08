/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:13:45 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 11:06:27 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_cmd_arg(t_list *node, bool *first)
{
	if (*first == true)
	{
		node->type = command;
		*first = false;
	}
	else
		node->type = argument;
}

static void	set_redirection(t_list *node, int macro)
{
	node->type = -1;
	node->next->type = macro;
	node = node->next->next;
}

//* Difference between assign_token and this is set_token is after error check
//* Set all redirection symbols to -1
//* Set all nodes after redirection to the redirection type
void	set_token(t_list **token_head)
{
	t_list	*tmp;
	bool	first;

	tmp = *token_head;
	first = true;
	while (tmp)
	{
		if (tmp->type == heredoc || (tmp->type == input)
			|| (tmp->type == append) || (tmp->type == trunc))
		{
			if (tmp->type == heredoc)
				set_redirection(tmp, heredoc);
			else if (tmp->type == input)
				set_redirection(tmp, input);
			else if (tmp->type == append)
				set_redirection(tmp, append);
			else if (tmp->type == trunc)
				set_redirection(tmp, trunc);
			tmp = tmp->next->next;
			continue ;
		}
		else if (tmp->type == piping)
			first = true;
		else
			set_cmd_arg(tmp, &first);
		tmp = tmp->next;
	}
}
