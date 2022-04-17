/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:13:07 by hloke             #+#    #+#             */
/*   Updated: 2022/03/22 20:17:29 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_oldpwd_pwd(char *oldpwd, char *pwd)
{
	char	*tmp;

	tmp = ft_strjoin("OLDPWD=", oldpwd);
	ft_putenv(tmp);
	free (tmp);
	tmp = ft_strjoin("PWD=", pwd);
	ft_putenv(tmp);
	free (tmp);
}

/*
	Changes the current directory.
*/
void	builtin_cd(t_cmd *node)
{
	char	*oldpwd;
	char	*pwd;

	if (ft_array_size(node->cmd_args) < 2)
	{
		ft_putstr_fd("bash: cd: wrong number of arguments\n", STDERR_FILENO);
		return (return_or_exit(node, EXIT_FAILURE));
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(node->cmd_args[1]) == -1)
	{
		free (oldpwd);
		ft_putstr_fd("bash: cd: ", STDERR_FILENO);
		ft_putstr_fd(node->cmd_args[1], STDERR_FILENO);
		ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		return (return_or_exit(node, EXIT_FAILURE));
	}
	pwd = getcwd(NULL, 0);
	set_oldpwd_pwd(oldpwd, pwd);
	free (oldpwd);
	free (pwd);
	return (return_or_exit(node, EXIT_SUCCESS));
}
