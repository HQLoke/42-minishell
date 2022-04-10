/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:16:12 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 18:16:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Don't know why I can't use ft_strchr to find matched character
static int	special_char_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[(i + 1) + len])
	{
		if (str[(i + 1) + len] == '$' || str[(i + 1) + len] == ' '
			|| str[(i + 1) + len] == '\0' || str[(i + 1) + len] == '\''
			|| str[(i + 1) + len] == '\"')
			break ;
		len += 1;
	}
	return (len);
}

static int	join_env_value(t_list *node, char *tmp, char *tmp2, char *tmp3)
{
	int	len;

	if (tmp == NULL)
	{
		tmp = ft_strjoin(tmp2, tmp3);
		free (tmp2);
		free (tmp3);
		node->content = tmp;
		return (0);
	}
	len = ft_strlen(tmp);
	tmp = ft_strjoin(tmp2, tmp);
	free (tmp2);
	tmp2 = ft_strjoin(tmp, tmp3);
	free (tmp);
	free (tmp3);
	node->content = tmp2;
	return (len);
}

static int	replace_dollar(t_list *node, int i)
{
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	len = special_char_len(node->content, i);
	if (len == 0)
		return (1);
	tmp2 = ft_substr(node->content, i + 1, len);
	tmp = ft_getenv(tmp2);
	free (tmp2);
	tmp2 = ft_substr(node->content, 0, i);
	tmp3 = ft_substr(node->content, i + 1 + len,
			ft_strlen(node->content) - (i + 1 + len));
	free (node->content);
	return (join_env_value(node, tmp, tmp2, tmp3));
}

void	expand_token(t_list *node)
{
	bool	expand;
	bool	dq;
	int		i;

	expand = true;
	dq = false;
	i = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\"')
			dq = !dq;
		if (node->content[i] == '\'' && dq == false)
			expand = !expand;
		if (node->content[i] == '$' && expand == true)
			i += replace_dollar(node, i);
		else
			i += 1;
	}
}
