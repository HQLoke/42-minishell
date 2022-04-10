/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:27:06 by hloke             #+#    #+#             */
/*   Updated: 2022/03/24 19:30:07 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* ft_memmove is used to move the 2nd quote 1 position in front
static int	remove_quote_pair(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[(i + 1) + len] != c)
		len += 1;
	ft_memmove(str + (i + 1) + len, str + (i + 2) + len,
		ft_strlen(str) - (i + 1) - len);
	ft_memmove(str + i, str + (i + 1), ft_strlen(str) - i);
	return (len);
}

//* This function removes the identical quote pair.
//* For example: "hello 'world"im'tony"byebye"birdie'
//* returns =>    hello 'worldimtony"byebye"birdie
void	trim_token(char *content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\'' || content[i] == '\"')
			i += remove_quote_pair(content, content[i], i);
		else
			i += 1;
	}
}
