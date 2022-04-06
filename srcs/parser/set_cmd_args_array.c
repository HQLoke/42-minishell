/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_args_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:07:50 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 15:14:47 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Put whatever that is not of redirection type into the array to be executed
void	set_cmd_args_array(t_mini *mini)
{
	t_list	*tmp;
	int		i;

	tmp = mini->redirect;
	i = 0;
	while (tmp)
	{
		if (tmp->type == 0)
		{
			mini->cmd_args[i] = ft_strdup(tmp->content);
			i += 1;
		}
		tmp = tmp->next;
	}
}
