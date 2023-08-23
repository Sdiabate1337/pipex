/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:30:05 by sdiabate          #+#    #+#             */
/*   Updated: 2023/07/23 16:30:13 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		ft_error("usage: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		outfile = open_file(argv[argc - 1], 0);
		ft_here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		outfile = open_file(argv[argc - 1], 1);
		infile = open_file(argv[1], 2);
		dup2(infile, STDIN_FILENO);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	dup2(outfile, STDOUT_FILENO);
	ft_execute(argv[argc - 2], envp);
	return (0);
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 6)
		ft_error("usage: ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <file>\n");
	if (pipe(fd) == -1)
		ft_error("pipe() failed!");
	pid = fork();
	if (pid == -1)
		ft_error("fork() failed!");
	if (pid == 0)
		ft_getline_write(limiter, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_pipe(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("pipe() failed!");
	pid = fork();
	if (pid == -1)
		ft_error("fork() failed!");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
