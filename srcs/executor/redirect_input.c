/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:51:59 by hloke             #+#    #+#             */
/*   Updated: 2022/03/25 12:18:50 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* heredoc <<
//* limit is the word that is used to stop heredoc
static int	input_heredoc(const char *limit)
{
	char	*tmp_filename;
	char	*line;
	int		tmp_fd;

	tmp_filename = ".heredoc_tmp";
	tmp_fd = ft_open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	while (1)
	{
		line = readline("heredoc> ");
		if (ft_strncmp(line, limit, ft_strlen(limit) + 1) == 0)
			break ;
		ft_putstr_fd(line, tmp_fd);
		ft_putstr_fd("\n", tmp_fd);
	}
	free (line);
	ft_close(tmp_fd);
	return (ft_open(tmp_filename, O_RDONLY, 0));
}

//* Opening and closing each file descriptor is required
//* To check for file opening errors and triggering heredoc
//* Returns file descriptor of the last input file
//* Returns -1 if no input redirection is found
int	redirect_input(t_list *redirect)
{
	t_list	*tmp;
	int		input_fd;

	tmp = redirect;
	input_fd = -1;
	while (tmp)
	{
		if (tmp->type == heredoc || tmp->type == input)
		{
			if (input_fd != -1)
				ft_close(input_fd);
			if (tmp->type == heredoc)
				input_fd = input_heredoc(tmp->content);
			else if (tmp->type == input)
				input_fd = ft_open(tmp->content, O_RDONLY, 0);
		}
		tmp = tmp->next;
	}
	return (input_fd);
}
