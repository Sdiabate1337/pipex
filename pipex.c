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

void    ft_execute(char *cmd, char **envp)
{
    char    **cmd_split;
    char    *path;

    cmd_split = ft_split(cmd, ' ');
    path = ft_find_path(cmd_split[0], envp);
    if (!path)
    {
        ft_free_2d(cmd_split);
        ft_error("PATH NOT FOUND!");
    }
    if (execve(path, cmd_split, envp) == -1)
        ft_error("EXCECUTION FAILED!");
}

char    *ft_find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *ab_path_root;
    char        *ab_path;
    int             i;

    i = 0;
    while (!ft_strnstr(envp[i], "PATH", 4))
        i++;
    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i])
    {
        ab_path_root = ft_strjoin(paths[i], "/");
        ab_path = ft_strjoin(ab_path_root, cmd);
        free(ab_path_root);
        if (access(ab_path, F_OK) == 0)
            return (ab_path);
        free(ab_path);
        i++;
    }
    ft_free_2d(paths);
    return (NULL);
}

void    ft_free_2d(char **str)
{
    int i;

    i = -1;
    while (str[++i])
        free(str[i]);
    free(str);
}

void    ft_error(char *err_msg)
{

    perror(err_msg);
    exit(EXIT_FAILURE);
}