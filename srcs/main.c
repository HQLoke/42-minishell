/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:45:51 by hloke             #+#    #+#             */
/*   Updated: 2022/03/24 18:44:42 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_mini	*mini_head;
	char	*input;

	mini_init(&mini_head);
	ft_signal();
    while (true)
    {
        input = readline("(づ｡◕‿‿◕｡)づ>> ");
		if (input == NULL)
			sigquit_handler();
		if (error_handling(input) == SUCCESS)
		{
			add_history(input);
			process_line(mini_head, input);
		}
		free(input);
    }
	mini_deinit(&mini_head);
	// system("leaks minishell");
	return (0);
}
