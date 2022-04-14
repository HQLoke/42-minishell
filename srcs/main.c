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

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_list		*token_head;
	t_cmd		*command_head;
	bool		lexer_ok;

	mini_init(&token_head, &command_head, envp);
	ft_signal();
	while (true)
	{
		input = readline("мιηιѕнєℓℓ (づ｡◕‿‿◕｡)づ ");
		if (input == NULL)
			sigquit_handler();
		add_history(input);
		lexer_ok = mini_lexer(input, &token_head);
		if (lexer_ok == true)
		{
			mini_parser(token_head, &command_head);
			mini_executor(command_head);
		}
		ft_lstclear(&token_head, free);
		unmake_cmd_list(&command_head);
		free(input);
	}
	return (0);
}
