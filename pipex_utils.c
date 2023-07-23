/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:30:22 by sdiabate          #+#    #+#             */
/*   Updated: 2023/07/23 16:30:31 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!ft_check(cmd[0]))
	{
		printf("hreeeee\n");
		path = ft_find_path(cmd[0], envp);
		if (!path)
		{
			ft_free_2d(cmd);
			ft_error("path not found!");
		}
	}
	else
		path = cmd[0];
	if (execve(path, cmd, envp) == -1)
		ft_error("execution failed!");
}

int	ft_check(char *cmd)
{
	if (ft_strncmp(cmd, "/", 1) == 0)
	{
		if (access(cmd, F_OK) == 0)
			return (1);
	}
	return (0);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths_split;
	char	*ab_path;
	int		i;
	char	*ab_path_root;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths_split[i])
	{
		ab_path_root = ft_strjoin(paths_split[i], "/");
		ab_path = ft_strjoin(ab_path_root, cmd);
		free(ab_path_root);
		if (access(ab_path, F_OK) == 0)
			return (ab_path);
		free(ab_path);
		i++;
	}
	ft_free_2d(paths_split);
	return (0);
}

void	ft_free_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}
