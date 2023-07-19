#ifndef PIPEX_H
# define PIPEX_H

# include "GET_NEXT_LINE/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

void    ft_child_proc(char **av, char **envp, int fd[2]);
void    ft_parent_proc(char **av, char **envp, int fd[2]);
void    ft_execute(char *cmd, char **envp);
char    *ft_find_path(char *cmd, char **envp);
void    ft_free_2d(char **str);
void    ft_error(char *err_msg);
void    ft_here_doc(char *limite, int ac);
void    ft_pipe(char *av, char **envp);


#endif