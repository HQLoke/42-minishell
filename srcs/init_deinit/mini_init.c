/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:06:07 by hloke             #+#    #+#             */
/*   Updated: 2022/04/06 17:26:14 by hloke            ###   ########.fr       */
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

//* Initialize at the start before reading input
void	mini_init(t_mini **mini)
{
	welcome_msg();
	*mini = ft_calloc(1, sizeof(t_mini));
	env_init(&(*mini)->env_head);
	(*mini)->pwd = NULL;
	(*mini)->pipeline_head = NULL;
	(*mini)->redirect = NULL;
	(*mini)->cmd_args = NULL;
	(*mini)->path = NULL;
}
