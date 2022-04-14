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

int	check_cd(char *current_path)
{
	int		i;

	i = chdir(current_path);
	if (i < 0)
	{
		printf("cd: %s: %s\n", current_path, strerror(errno));
		return (1);
	}
	return (0);
}

int	set_home_path(void)
{
	char	*path;
	int		i;

	i = 0;
	path = getenv("HOME");
	i = chdir(path);
	if (i < 0)
	{
		printf("cd: HOME not set\n");
		return (1);
	}
	return (0);
}

/*
	Changes the current directory.
*/
void	builtin_cd(t_cmd *node)
{
	int		status;
	char	*old_pwd_path;

	old_pwd_path = getcwd(NULL, 0);
	if (ft_array_size(node->cmd_args) > 2)
		printf("cd: too many arguments\n");
	if (old_pwd_path == NULL)
		return ;
	if (node->cmd_args[1] == NULL)
		status = set_home_path();
	if (ft_array_size(node->cmd_args) == 2)
		status = check_cd(node->cmd_args[1]);
	if (status == 0)
		status = check_pwd(&old_pwd_path);
	free(old_pwd_path);
	if (node->cmd_num == -2)
	{
		g_environ->exit_status = EXIT_SUCCESS;
		return ;
	}
	exit (EXIT_SUCCESS);
}
