
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
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc != 6)
		ft_error("here_doc usage:  ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <file>\n");
	if (pipe(fd) == -1)
		ft_error("pipe() failed!");
	pid = fork();
	if (pid == -1)
		ft_error("fork() failed!");
	if (pid == 0)
	{
		close(fd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void    ft_pipe(char *av, char **envp)
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

int	get_line(char **line)
{
	char	*buffer;
	int		i;
	int		lue;
	char	c;

	i = 0;
	lue = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	lue = read(0, &c, 1);
	while (lue && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		lue = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (lue);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error("file open failed!");
	return (file);
}