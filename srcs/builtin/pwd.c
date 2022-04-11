/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:18:00 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
     Prints the current working directory
*/
int	builtin_pwd(char **cmd)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (dir == NULL)
	{
		cd_error("pwd", NULL, strerror(errno));
		return (1);
	}
	printf("%s\n", dir);
	free(dir);
	//return (EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}
