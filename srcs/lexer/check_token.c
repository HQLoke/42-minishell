/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:47:25 by hloke             #+#    #+#             */
/*   Updated: 2022/04/14 14:19:23 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_lexer_ok(char *error_msg, bool *lexer_ok)
{
	ft_putstr_fd(error_msg, 2);
	*lexer_ok = false;
}

static void	check_quote(char *content, bool *lexer_ok)
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
				set_lexer_ok("😢 syntax error: unclosed quotes\n", lexer_ok);
			content += (i + 1);
		}
		else
			content += 1;
	}
}

//* Check if have open-ended quotes
//* Check if pipe is first/last/consecutive
//* Check if redirection is last/consecutive/followed by pipe
void	check_token(t_list **token_head, bool *lexer_ok)
{
	t_list	*tmp;
	int		index;

	tmp = *token_head;
	index = 0;
	while (tmp)
	{
		check_quote(tmp->content, lexer_ok);
		if (tmp->type == piping && (index == 0 || tmp->next == NULL
				|| tmp->next->type == piping))
			set_lexer_ok("😢 syntax error: pipe\n", lexer_ok);
		else if ((tmp->type >= heredoc && tmp->type <= trunc) \
			&& ((tmp->next == NULL) || (tmp->next->type >= heredoc \
			&& tmp->next->type <= trunc) || (tmp->next->type == piping)))
			set_lexer_ok("😢 syntax error: redirection\n", lexer_ok);
		index += 1;
		tmp = tmp->next;
	}	
}
