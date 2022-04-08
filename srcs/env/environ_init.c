/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:58:01 by hloke             #+#    #+#             */
/*   Updated: 2022/04/08 15:58:01 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	environ_init(char **envp)
{
	g_environ = ft_calloc(1, sizeof(t_environ));
	g_environ->num_var = ft_array_size(envp);
	g_environ->env_var = ft_array_dup(envp, g_environ->num_var);
}
