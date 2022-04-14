/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:06:07 by hloke             #+#    #+#             */
/*   Updated: 2022/04/14 11:14:03 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	welcome_msg(void)
{
	printf(RED"	        _                                              \n");
	printf(YEL"__      __ ___ | |  ___  ___   _ __ ___    ___               \n");
	printf(GRN"\\ \\ /\\ / // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\       \n");
	printf(BLU" \\ V  V /|  __/| || (__| (_) || | | | | ||  __/             \n");
	printf(MAG"  \\_/\\_/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|        \n");
	printf(RED" _                      _         _       _            _  _  \n");
	printf(YEL"| |_  ___    _ __ ___  (_) _ __  (_) ___ | |__    ___ | || | \n");
	printf(GRN"| __|/ _ \\  | '_ ` _ \\ | || '_ \\ | |/ __|| '_ \\  / _ \\| || |\n");
	printf(BLU"| |_| (_) | | | | | | || || | | || |\\__ \\| | | ||  __/| || |\n");
	printf(MAG" \\__|\\___/  |_| |_| |_||_||_| |_||_||___/|_| |_| \\___||_||_|\n");
	printf(BHCYN);
}

void	mini_init(t_list **token_head, t_cmd **command_head, char **envp)
{
	welcome_msg();
	*token_head = NULL;
	*command_head = NULL;
	g_environ = ft_calloc(1, sizeof(t_environ));
	g_environ->num_var = ft_array_size(envp);
	g_environ->env_var = ft_array_dup(envp, g_environ->num_var);
}
