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

/*
	Changes the current working directory to the given path with chdir and
	Change the env $PWD and $OLDPWD.
*/

static int	check_pwd(char **cmd)
{
	char	*old_pwd_path;

	if (ft_getenv("OLDPWD"))
	{
		if (ft_getenv("PWD"))
			old_pwd_path = ft_strjoin("OLDPWD=", ft_getenv("PWD"));
		else
			old_pwd_path = ft_strdup("OLDPWD=");
	}
	*cmd = getcwd(NULL, 0);
	old_pwd_path = ft_strjoin("PWD=", *cmd);
	if (old_pwd_path == NULL || *cmd == NULL)
		return (1);
	free(old_pwd_path);
	return (0);
}

static char	*ft_getcwd(t_cmd *node)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		g_environ->exit_status = EXIT_FAILURE;
		ft_putstr_fd("error: ft_getcwd\n", STDERR_FILENO);
		if (node->cmd_num == -2)
			return (NULL);
		exit (EXIT_FAILURE);
	}
	return (cwd);
}

/*
	Changes the current directory.
*/
void	builtin_cd(t_cmd *node)
{
	char	*pwd;
	char	*oldpwd;
	int		ret;

	if (node->cmd_args[1] == NULL || ft_strncmp(node->cmd_args[1], "~", 2) == 0)
		pwd = ft_getenv("HOME");
	else if (ft_strncmp(node->cmd_args[1], "-", 2) == 0)
		pwd = ft_getenv("OLDPWD");
	else
		pwd = ft_getcwd(node);
	oldpwd = ft_getcwd(node);
	if (oldpwd == NULL)
	{
		g_environ->exit_status = EXIT_FAILURE;
		if (node->cmd_num == -2)
			return;
		exit (EXIT_FAILURE);
	}
	ret = chdir(node->cmd_args[1]);
	if (ret == -1)
	{
		free (oldpwd);
		ft_putstr_fd("bash: cd: ", STDERR_FILENO);
		ft_putstr_fd(node->cmd_args[1], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		g_environ->exit_status = EXIT_FAILURE;
		if (node->cmd_num == -2)
			return (EXIT_FAILURE);
		exit (EXIT_FAILURE);
	}
	pwd = 

	if (node->cmd_num == -2)
		return ;
	exit (EXIT_SUCCESS);
}
