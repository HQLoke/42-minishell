/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_deinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:06:32 by hloke             #+#    #+#             */
/*   Updated: 2022/04/06 18:03:44 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	goodbye_msg(void)
{
	printf(RED" _                    _                        \n");
	printf(YEL"| |__   _   _   ___  | |__   _   _   ___       \n");
	printf(GRN"| '_ \\ | | | | / _ \\ | '_ \\ | | | | / _ \\  \n");
	printf(BLU"| |_) || |_| ||  __/ | |_) || |_| ||  __/      \n");
	printf(MAG"|_.__/  \\__, | \\___| |_.__/  \\__, | \\___|  \n");
	printf(RED"        |___/                |___/             \n");
	printf(YEL" _                                         \n");
	printf(GRN"| |__    __ _ __   __ ___    __ _          \n");
	printf(BLU"| '_ \\  / _` |\\ \\ / // _ \\  / _` |     \n");
	printf(MAG"| | | || (_| | \\ V /|  __/ | (_| |        \n");
	printf(RED"|_| |_| \\__,_|  \\_/  \\___|  \\__,_|     \n");
	printf(YEL"        _                  _                  __       \n");
	printf(GRN" _ __  (_)  ___  ___    __| |  __ _  _   _   _\\ \\    \n");
	printf(BLU"| '_ \\ | | / __|/ _ \\  / _` | / _` || | | | (_)| |   \n");
	printf(MAG"| | | || || (__|  __/ | (_| || (_| || |_| |  _ | |     \n");
	printf(RED"|_| |_||_| \\___|\\___|  \\__,_| \\__,_| \\__, | (_)| |\n");
	printf(YEL"                                     |___/    /_/      \n");
	printf(RESET);
}

//* Deinitialize at EXIT_FAILURE or at the end of program
void	mini_deinit(t_mini **mini)
{
	goodbye_msg();
	env_deinit(&(*mini)->env_head);
	ft_free ((*mini)->pwd);
	ft_lstclear(&(*mini)->pipeline_head, free);
	ft_lstclear(&(*mini)->redirect, free);
	ft_memdel((void **)(*mini)->cmd_args);
	ft_memdel((void **)(*mini)->path);
	ft_free (*mini);
	*mini = NULL;
}
