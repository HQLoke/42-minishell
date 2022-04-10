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
	token_head = NULL;

	environ_init(envp);
	ft_signal();
    // while (true)
    {
        input = readline("мιηιѕнєℓℓ (づ｡◕‿‿◕｡)づ ");
		if (input == NULL)
			sigquit_handler();

		add_history(input);
		mini_lexer(input, &token_head);
		mini_parser(token_head);

		t_list *tmp;
		tmp = token_head;
		while (tmp)
		{
			printf("Type is %i, %s\n", tmp->type, tmp->content);
			tmp = tmp->next;
		}

		ft_lstclear(&token_head, free);
		free(input);
    }
	system("leaks minishell");
	return (0);
}
