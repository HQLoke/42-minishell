/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:42:29 by hloke             #+#    #+#             */
/*   Updated: 2022/03/31 17:39:01 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Combination of ft_lstnew & ft_lstadd_back
//* Create a new list for head if NULL
//* Else traverse till the end to add a new list
void	ft_new_addback(t_list **head, char *content, int type)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_calloc(1, sizeof(t_list));
	new->content = ft_strdup(content);
	new->type = type;
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
