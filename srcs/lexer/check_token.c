/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:47:25 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 10:08:22 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_quote(char *content)
{
	int	i;

	while (*content)
	{
		i = 1;
		if (*content == '\'' || *content == '\"')
		{
			while (content[i] != *content && content[i])
				i += 1;
			if (content[i] == '\0')
				ft_error_exit("😢 syntax error: unclosed quotes\n");
			content += (i + 1);
		}
		else
			content += 1;
	}
}

//* Check if have open-ended quotes
//* Check if pipe is first/last/consecutive
//* Check if redirection is last/consecutive/followed by pipe
void	check_token(t_list **token_head)
{
	t_list	*tmp;
	int		index;

	tmp = *token_head;
	index = 0;
	while (tmp)
	{
		check_quote(tmp->content);
		if (tmp->type == piping && (index == 0 || tmp->next == NULL
			|| tmp->next->type == piping))
			ft_error_exit("😢 syntax error: pipe\n");
		else if ((tmp->type >= heredoc && tmp->type <= trunc)
			&& ((tmp->next == NULL) || (tmp->next->type >= heredoc 
			&& tmp->next->type <= trunc) || (tmp->next->type == piping)))
			ft_error_exit("😢 syntax error: redirection\n");
		index += 1;
		tmp = tmp->next;
	}	
}
