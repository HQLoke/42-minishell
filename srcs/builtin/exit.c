/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:22 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:42 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Prints exit and error message. 
	minishell is closed and the exit code and terminates it.
*/

static int	check_int_max(char	*arg)
{
	long long	n;
	int			i;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		n = n * 10 + arg[i] - '0';
		if (n > INT_MAX || n * sign < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	atoi_exit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ')
		i++;
	if ((arg[i] == '-' || arg[i] == '+') && !ft_isdigit(arg[++i]))
		return (0);
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	while (arg[i] == ' ')
		i++;
	if (!arg[i])
		return (1);
	return (0);
}

void	builtin_exit(t_cmd *node)
{
	int	status;

	status = 0;
	ft_putstr_fd("exit\n", 2);
	if (ft_array_size(node->cmd_args) > 2)
	{
		printf("%s: exit: too many arguments\n", node->cmd_args[1]);
		g_environ->exit_status = 1;
		return ;
	}
	else if (node->cmd_args[1] && (!atoi_exit(node->cmd_args[1])
			|| check_int_max(node->cmd_args[1])))
	{
		printf("%s: exit: numeric argument required\n", node->cmd_args[1]);
		status = 255;
	}
	else if (node->cmd_args[1])
		status = ft_atoi(node->cmd_args[1]) % 256;
	if (status == -1)
		status = 255;
	exit(status);
}
