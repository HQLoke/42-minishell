/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:54:16 by hloke             #+#    #+#             */
/*   Updated: 2022/04/07 19:28:18 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_dollar1(char **str, char *env_value, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(*str, 0, *i);
	tmp2 = ft_substr(*str, *i + 1, ft_strlen(*str) - (*i + 1));
	tmp3 = ft_strjoin(tmp, env_value);
	free(tmp);
	tmp = ft_strjoin(tmp3, tmp2);
	free(tmp2);
	free(tmp3);
	free(*str);
	*str = tmp;
	*i += ft_strlen(env_value);
}

void	expand_dollar1(t_list **token_head, t_list *expansion)
{
	int		i;
	t_list	*tmp;
	t_list	*temp;

	tmp = expansion;
	temp = *token_head;
	while (temp)
	{
		i = 0;
		while ((temp->content)[i] != '\0')
		{
			if ((temp->content)[i] == '$')
			{
				if (tmp->type == 0)
					i += 1;
				else
					replace_dollar1(&(temp->content), tmp->content, &i);
				tmp = tmp->next;
			}
			else
				i += 1;
		}
		temp = temp->next;
	}
}

static char	*env_value1(t_mini *mini, char *str, int expand, int i)
{
	int		len;
	char	*tmp;
	char	*ret;

	len = 0;
	if (str[i + 1] == '?')
	{
		if (expand == 1)
			ft_memmove(str + (i + 1), str + (i + 2), ft_strlen(str) - i - 1);
		return (ft_itoa(mini->last_exit_status));
	}
	while (str[(i + 1) + len])
	{
		if (ft_strchr("$ \0\'\"", str[(i + 1) + len]) != NULL)
			break ;
		len += 1;
	}
	tmp = ft_substr(str, i + 1, len);
	ret = env_get_value(mini->env_head, tmp);
	free(tmp);
	if (expand == 1)
		ft_memmove(str + (i + 1), str + (i + 1) + len,
			ft_strlen(str) - i - len);
	return (ret);
}

void	extract_expansion1(t_mini *mini, t_list **token_head, t_list **expansion)
{
	bool	expand;
	int		i;
	char	*tmp;
	t_list	*temp;

	expand = true;
	temp = *token_head;
	while (temp)
	{
		i = 0;
		while ((temp->content)[i])
		{
			if ((temp->content)[i] == '\'')
				expand = !expand;
			if ((temp->content)[i] == '$')
			{
				tmp = env_value1(mini, temp->content, expand, i);
				ft_new_addback(expansion, tmp, expand);
				free (tmp);
			}
			i += 1;
		}
		temp = temp->next;
	}
}

void	expand_token(t_mini *mini, t_list **token_head)
{
	// t_list	*tmp;

	// tmp = *token_head;
	// while (tmp)
	// {
	// 	tmp = tmp->next;
	// }
	t_list *expansion;

	expansion = NULL;
	extract_expansion1(mini, token_head, &expansion);
	expand_dollar1(token_head, expansion);

	t_list *token;
	token = *token_head;
	while (token)
	{
		printf("%s\n", token->content);
		token = token->next;
	}
	ft_lstclear(token_head, free);
	ft_lstclear(&expansion, free);
}
