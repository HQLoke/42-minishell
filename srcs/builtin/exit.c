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
static int	check_int_max(int sign, char *arg, long long n)
{
	int len;

    len = ft_isdigit(arg[1]);
    if (len == 0)
		return (0);
    n *= sign;
	if (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && arg[1] > '7'))
        return (1);
    else if (n < LONG_MIN / 10 || (n == LONG_MIN / 10 && arg[1] > '8'))
        return (1);
	return (0);
}

static int	atoi_exit(char *arg)
{
	int			sign;
	long long	i;

	sign = 1;
	i = 0;
	while ((*arg >= '\t' && *arg <= '\r') || *arg == ' ')
		arg++;
	if (*arg == '-')
	{
		sign *= -1;
		arg++;
	}
	else if (*arg == '+')
		arg++;
	while (*arg && ft_isdigit(*arg))
	{
        if (i)
			i *= 10;
		i += *arg - '0';
		if (check_int_max(sign, arg, i) == 1)
			return (0);
		arg++;
	}
	if (*arg != '\0')
		return (0);
    return (1);
}

int	builtin_exit(t_cmd *node)
{
	unsigned char	status;
	
	status = 0;
	if (node->cmd_args[1])
	{
		if (atoi_exit(node->cmd_args[1]))
		{
			status = ft_atoi(node->cmd_args[1]);
		}
			
		else
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(node->cmd_args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			status = 255;
		}
	}
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(status, 2);
	ft_putstr_fd("\n", 2);
	return(status);
}
