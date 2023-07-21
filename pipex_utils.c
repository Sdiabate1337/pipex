
#include "pipex.h"

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