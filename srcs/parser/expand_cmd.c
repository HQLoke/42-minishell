/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:24:07 by hloke             #+#    #+#             */
/*   Updated: 2022/04/10 17:46:05 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Split command token by space delimiter
//* Example: HELLO=ls -la will split into ls -la
void	expand_cmd(t_list *node)
{
	char	**cmd;
	t_list	*next;
	int		i;
	
	cmd = ft_split(node->content, ' ');
	next = node->next;
	node->next = NULL;
	i = 1;
	if (ft_array_size(cmd) != 1)
	{
		free (node->content);
		node->content = ft_strdup(cmd[0]);
		while (cmd[i] != NULL)
		{
			ft_lstadd_back(&node, ft_lstnew(ft_strdup(cmd[i]), argument));
			i += 1;
		}
		ft_lstlast(node)->next = next;
	}
	ft_memdel((void **)cmd);
}
