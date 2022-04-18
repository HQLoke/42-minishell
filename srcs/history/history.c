/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:54:31 by hloke             #+#    #+#             */
/*   Updated: 2022/04/18 23:20:13 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* does not add empty string into history
void	history_append(char *input)
{
	int	fd;

	if (input == NULL)
		return ;
	if (ft_strlen(input) != 0)
	{
		fd = ft_open("./srcs/history/.all_history",
			O_CREAT | O_WRONLY | O_APPEND, 0666);
		ft_putendl_fd(input, fd);
		add_history(input);
		ft_close (fd);
	}
	return ;
}

void	history_init(void)
{
	int		fd;
	char	*line;

	fd = ft_open("./srcs/history/.all_history", O_RDONLY, 0);
	while (get_next_line(fd, &line) != 0)
	{
		add_history(line);
		free (line);
	}
	free (line);
	ft_close (fd);
}
