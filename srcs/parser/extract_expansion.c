/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:30:45 by hloke             #+#    #+#             */
/*   Updated: 2022/04/06 19:23:29 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Example: $PATH, len will return 4
//* Then will pass PATH through the env linked list to get the env value
//* Remove the env_var from the string
//* Return expanded env_var or empty string
static char	*env_value(t_mini *mini, char *str, int expand, int i)
{
	int		len;
	char	*tmp;
	char	*ret;

	len = 0;
	while (str[(i + 1) + len])
	{
		if (str[(i + 1) + len] == '$' || str[(i + 1) + len] == ' '
			|| str[(i + 1) + len] == '\0' || str[(i + 1) + len] == '\''
			|| str[(i + 1) + len] == '\"')
			break ;
		len += 1;
	}
	tmp = ft_substr(str, i + 1, len);
	if (ft_strncmp(tmp, "?", 2) == 0)
		ret = ft_itoa(mini->last_exit_status);
	else
		ret = env_get_value(mini->env_head, tmp);
	free(tmp);
	if (expand == 1)
		ft_memmove(str + (i + 1), str + (i + 1) + len,
			ft_strlen(str) - i - len);
	return (ret);
}

//* Type == 0 (not expand), content = NULL
//* Type == 1 (expand), content = environment value
static void	add_expansion(t_list **expansion, char *env_value, int type)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_calloc(1, sizeof(t_list));
	new->content = ft_strdup(env_value);
	new->type = type;
	new->next = NULL;
	tmp = *expansion;
	if (*expansion == NULL)
		*expansion = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//* For example: $PATH"hello"$RANDOM'$USER' will become $"hello"$'$'
//* Find all dollar signs & set the type to 0 (not expand) or 1 (expand)
//* If expand, use env_get_value to get content and set in the linked list
//* ft_memmove to delete the environment variable
void	extract_expansion(t_mini *mini, char **cmd_args, t_list **expansion)
{
	bool	expand;
	int		i;
	char	*tmp;

	expand = true;
	while (*cmd_args)
	{
		i = 0;
		while ((*cmd_args)[i])
		{
			if ((*cmd_args)[i] == '\'')
				expand = !expand;
			if ((*cmd_args)[i] == '$')
			{
				tmp = env_value(mini, *cmd_args, expand, i);
				add_expansion(expansion, tmp, expand);
				free (tmp);
			}
			i += 1;
		}
		cmd_args += 1;
	}
}
