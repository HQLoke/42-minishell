/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:25:47 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 15:52:30 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* N = number of processes
//* If N > 1,  cmd = 0  means first process
//*            cmd > 0  means middle process
//*            cmd = -1 means last process
//* If N == 1, cmd = -2 means first & last, or one and only process
void	process_line(t_mini *mini, const char *line)
{
	t_list	*tmp;
	int		cmd;

	ft_split_custom(&mini->pipeline_head, line, '|');
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
