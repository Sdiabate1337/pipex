
#include "pipex.h"

int main(int ac, char **av, char **envp)
{
    int i;
    int infile;
    int outfile;

    if (ac < 5)
        ft_error("usage : ");
    if (ft_strncmp(av[1], "here_doc", 8) == 0)
    {
        i = 3;
        outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
        ft_here_doc(av[2], ac);
    }
    else
    {
        i = 2;
        infile = open(av[1], O_RDONLY);
        outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
        dup2(infile, STDIN_FILENO);
    }
    while (i < ac - 2)
        ft_pipe(av[i], envp);
    dup2(outfile, STDOUT_FILENO);
    ft_execute(av[ac - 2], envp);
}

void    ft_here_doc(char *limite, int ac)
{
    pid_t   pid;
    int     fd[2];
    char    *line;

    if (pipe(fd) == -1)
        ft_error("PIPE() FAILED!");
    pid = fork();
    if (pid == -1)
        ft_error("FORK() FAILED!");
    if (pid == 0)
    {
        close(fd[0]);
        line = get_next_line(0);
        while (line != NULL)
        {
            if (ft_strncmp(line, limite, ft_strlen(limite)) == 0)
                exit(EXIT_SUCCESS);
            write(fd[1], line, ft_strlen(line));
            line = get_next_line(0);
        }
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

void    ft_pipe(char *av, char **envp)
{
    pid_t   pid;
    int     fd[2];

    if (pipe(fd) == -1)
        ft_error("PIPE() FAILED!");
    pid = fork();
    if (pid == -1)
        ft_error("FORK() FAILED!");
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