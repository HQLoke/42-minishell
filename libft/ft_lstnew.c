/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:32 by hloke             #+#    #+#             */
/*   Updated: 2022/02/23 13:56:33 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*node;

	node = malloc(sizeof (*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->type = type;
	node->next = NULL;
	return (node);
}
