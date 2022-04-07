/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:25:47 by hloke             #+#    #+#             */
/*   Updated: 2022/04/07 15:20:06 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Split pipeline into tokens
//* Set command with arguments, put in cmd_args array
//* Keep all filesnames and its type, put in redirect linked list
//* Set the path to pass to execve, put in path array
//* Extract expansion data and put in expansion linked list
//* Trim quotes in cmd_args
//* Expand dollar signs in cmd_args
//* Send to executor to process redirections & command execution
//* Free variables that are used in each pipeline after successful execution
//* i.e: redirect, cmd_args, path
static void	parse_line(t_mini *mini, const char *content, int cmd)
{
	char		*path_tmp;
	t_list		*expansion;

	expansion = NULL;
	ft_tokenizer(&mini->redirect, content, ' ');
	mini->cmd_args = ft_calloc(count_cmd_args(mini->redirect) + 1,
			sizeof(char *));
	set_cmd_args_array(mini);
	path_tmp = env_get_value(mini->env_head, "PATH");
	mini->path = ft_split(path_tmp, ':');
	free(path_tmp);
	extract_expansion(mini, mini->cmd_args, &expansion);
	trim_quotes(mini->cmd_args);
	expand_dollar(mini->cmd_args, expansion);
	ft_lstclear(&expansion, free);
	executor(mini, cmd);
	ft_lstclear(&mini->redirect, free);
	ft_memdel((void **)mini->cmd_args);
	mini->cmd_args = NULL;
	ft_memdel((void **)mini->path);
	mini->path = NULL;
}

//* N = number of processes
//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	process_line(t_mini *mini, const char *line)
{
	t_list	*tmp;
	int		cmd;

	ft_tokenizer(&mini->pipeline_head, line, '|');
	tmp = mini->pipeline_head;
	cmd = 0;
	while (tmp)
	{
		if ((tmp->next == NULL) && (cmd > 0))
			cmd = -1;
		else if ((tmp->next == NULL) && (cmd == 0))
			cmd = -2;
		parse_line(mini, tmp->content, cmd);
		cmd += 1;
		tmp = tmp->next;
	}
	wait_exit_status(mini);
	ft_lstclear(&mini->pipeline_head, free);
}
