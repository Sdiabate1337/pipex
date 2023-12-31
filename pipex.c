/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:29:33 by sdiabate          #+#    #+#             */
/*   Updated: 2023/07/23 16:29:40 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_error("usage : ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	if (pipe(fd) == -1)
		ft_error("pipe() failed!");
	pid = fork();
	if (pid == -1)
		ft_error("fork() failed!");
	if (pid == 0)
		ft_child_proc(argv, envp, fd);
	waitpid(pid, NULL, 0);
	ft_parent_proc(argv, envp, fd);
	return (0);
}

void	ft_child_proc(char **argv, char **envp, int fd[2])
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error("infile open failed!");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	ft_execute(argv[2], envp);
}

void	ft_parent_proc(char **argv, char **envp, int fd[2])
{
	int	outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error("outfile open failed!");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	ft_execute(argv[3], envp);
}
