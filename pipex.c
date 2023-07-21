 #include "pipex.h"
 
int main(int ac, char **av, char **envp)
{
    int fd[2]; /*
                fd[0] for reading; fd[1] for writing
                the output of fd1 becomes the input for fd0.
                */ 
    pid_t   pid1;

    if (ac != 5)
        ft_error("usage : ./pipex infile cmd1 cmd2 outfile");
    if (pipe(fd) == -1)
        ft_error("PIPE() FAILED!");
    pid1 = fork();
    if (pid1 == -1)
        ft_error("FORK() FAILED!");
    if (pid1 == 0)
        ft_child_proc(av, envp, fd);
    waitpid(pid1, NULL, 0);
    ft_parent_proc(av, envp, fd);
    return (0);
}

void    ft_child_proc(char **av, char **envp, int fd[2])
{
    int infile;

    infile = open(av[1], O_RDONLY);
    if (infile == -1)
        ft_error("OPEN INFILE FAILED!");
    dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
    close(fd[0]);
    ft_execute(av[2], envp);
}

void    ft_parent_proc(char **av, char **envp, int fd[2])
{
    int outfile;

    outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (outfile == -1)
        ft_error("OPEN OUTFILE FAILED!");
    dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
    close(fd[1]);
    ft_execute(av[3], envp);
}