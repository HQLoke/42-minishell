/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:28:15 by hloke             #+#    #+#             */
/*   Updated: 2022/04/12 16:17:38 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_cmd_num(t_cmd **command_head)
{
	t_cmd	*tmp;
	int		cmd;

	tmp = *command_head;
	cmd = 0;
	while (tmp)
	{
		if (cmd == 0 && tmp->next == NULL)
			tmp->cmd_num = -2;
		else if (cmd != 0 && tmp->next == NULL)
			tmp->cmd_num = -1;
		else
			tmp->cmd_num = cmd;
		cmd += 1;
		tmp = tmp->next;
	}
}

static void	add_command(t_cmd **command_head)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = ft_calloc(1, sizeof(t_cmd));
	new->redirect = NULL;
	new->cmd_args = NULL;
	new->next = NULL;
	tmp = *command_head;
	if (*command_head == NULL)
		*command_head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	make_cmd_list(t_list *token_head, t_cmd **command_head, int pipe_count)
{
	t_list	*token_tmp;
	t_cmd	*cmd_tmp;
	char	**tmp;

	while (pipe_count-- > 0)
		add_command(command_head);
	set_cmd_num(command_head);
	token_tmp = token_head;
	cmd_tmp = *command_head;
	while (token_tmp)
	{
		if (token_tmp->type >= heredoc && token_tmp->type <= trunc)
			ft_lstadd_back(&(cmd_tmp->redirect),
				ft_lstnew(ft_strdup(token_tmp->content), token_tmp->type));
		else if (token_tmp->type >= command && token_tmp->type <= argument)
			cmd_tmp->cmd_args = ft_array_add(cmd_tmp->cmd_args,
					token_tmp->content);
		else if (token_tmp->type == piping)
			cmd_tmp = cmd_tmp->next;
		token_tmp = token_tmp->next;
	}
}

void	unmake_cmd_list(t_cmd **command_head)
{
	t_cmd	*next;

	while (*command_head)
	{
		next = (*command_head)->next;
		ft_lstclear(&(*command_head)->redirect, free);
		ft_memdel((void **)(*command_head)->cmd_args);
		free (*command_head);
		*command_head = next;
	}
	*command_head = NULL;
}
