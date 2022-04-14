/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:34:43 by hloke             #+#    #+#             */
/*   Updated: 2022/03/29 10:34:43 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* For tmp->type == trunc, if not the last output file
//* use O_TRUNC to create a new file for each output
//* Returns file descriptor of the last output file
//* Returns -1 if no output redirection is found
int	redirect_output(t_list *redirect)
{
	t_list	*tmp;
	int		output_fd;

	tmp = redirect;
	output_fd = STDOUT_FILENO;
	while (tmp)
	{
		if (tmp->type == append || tmp->type == trunc)
		{
			if (output_fd != STDOUT_FILENO)
				ft_close(output_fd);
			if (tmp->type == append)
				output_fd = ft_open(tmp->content, O_CREAT | O_WRONLY
						| O_APPEND, 0666);
			else if (tmp->type == trunc)
				output_fd = ft_open(tmp->content, O_CREAT | O_WRONLY
						| O_TRUNC, 0666);
		}
		tmp = tmp->next;
	}
	return (output_fd);
}
