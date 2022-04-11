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

#include "../../include/minishell.h"

void	cd_error(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s3, 2);
	ft_putstr_fd("\n", 2);
}

/*
	Changes the current working directory to the given path with chdir and
	Change the env $PWD and $OLDPWD.
*/
int	check_pwd(char **cmd)
{
	char	*old_pwd_path;
	old_pwd_path = ft_strjoin("OLDPWD=", *cmd);
	if (old_pwd_path == NULL)
		return (1);
	free(*cmd);
	free(old_pwd_path);
	*cmd = getcwd(NULL, 0);
	if (*cmd == NULL)
		return (1);
	old_pwd_path = ft_strjoin("PWD=", *cmd);
	if (old_pwd_path == NULL)
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
		cd_error("cd", current_path, strerror(errno));
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
		cd_error("cd", NULL, "HOME not set");
		return (1);
	}
	return (0);
}

/*
	Changes the current directory.
*/
int	builtin_cd(char **cmd)
{
	int		status;
	char	*old_pwd_path;

	old_pwd_path = getcwd(NULL, 0);
	if (old_pwd_path == NULL)
		return (EXIT_FAILURE);
	if (cmd[1] == NULL)
		status = set_home_path();
	else
		status = check_cd(cmd[1]);
	if (status == 0)
		status = check_pwd(&old_pwd_path);
	free(old_pwd_path);
	return (EXIT_SUCCESS);
}
