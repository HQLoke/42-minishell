/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:20:53 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 13:31:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Assign redirection type to symbol and the next content
static void	assign_redirection(t_list *list, int macro)
{
	list->type = -1;
	list->next->type = macro;
}

//* Calculate how many commands and arguments in total
int	count_cmd_args(t_list *head)
{
	t_list	*tmp;
	int		count;

	tmp = head;
	count = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "<<", 3) == 0)
			assign_redirection(tmp, LESSLESS);
		else if (ft_strncmp(tmp->content, "<", 2) == 0)
			assign_redirection(tmp, LESS);
		else if (ft_strncmp(tmp->content, ">>", 3) == 0)
			assign_redirection(tmp, GREATGREAT);
		else if (ft_strncmp(tmp->content, ">", 2) == 0)
			assign_redirection(tmp, GREAT);
		else
			count += 1;
		tmp = tmp->next;
	}
	return (count);
}
