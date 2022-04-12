/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:06:00 by hloke             #+#    #+#             */
/*   Updated: 2022/04/12 16:46:44 by hloke            ###   ########.fr       */
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

static	void	add_expand(char *content, t_list **expansion, int expand, int i)
{
	int		len;
	char	*tmp;
	char	*env_value;

	len = special_char_len(content, i);
	tmp = ft_substr(content, i + 1, len);
	if (ft_strncmp(tmp, "?", 2) == 0)
		env_value = ft_itoa(g_environ->exit_status);
	else
		env_value = ft_getenv(tmp);
	if (expand == 1)
		ft_memmove(content + (i + 1), content + (i + 1) + len,
			ft_strlen(content) - i - len);
	if (env_value == NULL)
		ft_lstadd_back(expansion, ft_lstnew(NULL, expand));
	else
		ft_lstadd_back(expansion, ft_lstnew(ft_strdup(env_value), expand));
	if (ft_strncmp(tmp, "?", 2) == 0)
		free (env_value);
	free (tmp);
}

void	get_expansion(char *content, t_list **expansion)
{
	int		i;
	bool	expand;
	bool	dq;

	i = 0;
	expand = true;
	dq = false;
	while (content[i])
	{
		if (content[i] == '\"')
			dq = !dq;
		if (content[i] == '\'' && dq == false)
			expand = !expand;
		if (content[i] == '$')
			add_expand(content, expansion, expand, i);
		i += 1;
	}
}
