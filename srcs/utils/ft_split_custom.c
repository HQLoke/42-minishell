/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:18:51 by hloke             #+#    #+#             */
/*   Updated: 2022/04/12 16:18:51 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Find out the length between single/double quotes
//* Add 1 if not end of line, to include the last quote
static int	quote_len(const char *str)
{
	int	i;

	i = 1;
	if (*str == '\'')
	{
		while (str[i] && str[i] != '\'')
			i += 1;
	}
	else if (*str == '\"')
	{
		while (str[i] && str[i] != '\"')
			i += 1;
	}
	return (i + 1);
}

//* Splits single quotes and double quotes into its own string
void	ft_split_custom(t_list **head, const char *input, char c)
{
	int		i;
	char	*tmp;

	while (*input)
	{
		i = 0;
		if (*input != c || *input == '\'' || *input == '\"')
		{
			while (input[i] != c && input[i])
			{
				if (input[i] == '\'' || input[i] == '\"')
					i += quote_len(input + i);
				else
					i += 1;
			}
			tmp = ft_substr(input, 0, i);
			ft_lstadd_back(head, ft_lstnew(tmp, 0));
			input += i;
		}
		else
			input += 1;
	}
}
