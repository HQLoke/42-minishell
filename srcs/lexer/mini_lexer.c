/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:47:48 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 14:07:00 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Returns the distance between single/double quotes
//* Return (i) if no quote at the end of string, else return (i + 1)
static int	len_quotes(char *input)
{
	int		i;

	i = 1;
	while ((input[i] != input[0]) && input[i])
		i += 1;
	if (input[i] == '\0')
		return (i);
	return (i + 1);
}

static int	token_string(t_list **token_head, char *input)
{
	int		i;
	char	*tmp;

	i = 0;
	while (input[i] && (ft_strchr("|<> ", input[i]) == NULL))
	{
		if (input[i] == '\'' || input[i] == '\"')
			i += len_quotes(input + i);
		else
			i += 1;
	}
	tmp = ft_substr(input, 0, i);
	ft_new_addback(token_head, tmp, 0);
	free (tmp);
	return (i);
}

static int	token_pipe(t_list **token_head, char *input)
{
	char	*tmp;

	tmp = ft_substr(input, 0, 1);
	ft_new_addback(token_head, tmp, 0);
	free (tmp);
	return (1);
}

static int	token_redirect(t_list **token_head, char *input)
{
	char	*tmp;

	if (input[0] == input[1])
	{
		tmp = ft_substr(input, 0, 2);
		ft_new_addback(token_head, tmp, 0);
		free (tmp);
		return (2);
	}
	tmp = ft_substr(input, 0, 1);
	ft_new_addback(token_head, tmp, 0);
	free (tmp);
	return (1);
}

//* Biggest mistake was that I used space as a delimiter
//* Split any string into a list of tokens
//* This will not handle a lot of cases, mainly just scan for redirections
void	mini_lexer(char *input, t_list **token_head)
{
	while (*input)
	{
		if (ft_strchr("|<> ", *input) == NULL)
			input += token_string(token_head, input);
		else if (*input == '|')
			input += token_pipe(token_head, input);
		else if (*input == '<' || *input == '>')
			input += token_redirect(token_head, input);
		else if (*input == ' ')
			input += 1;
	}
	assign_token(token_head);
	check_token(token_head);
	set_token(token_head);
}
