/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:29:55 by sdiabate          #+#    #+#             */
/*   Updated: 2023/07/23 16:29:58 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_child_proc(char **av, char **envp, int fd[2]);
void	ft_parent_proc(char **av, char **envp, int fd[2]);
void	ft_execute(char *cmd, char **envp);
char	*ft_find_path(char *cmd, char **envp);
void	ft_free_2d(char **str);
void	ft_error(char *err_msg);
void	ft_here_doc(char *limite, int ac);
void	ft_pipe(char *av, char **envp);
int		get_line(char **line);
int		open_file(char *argv, int i);
int		ft_check(char *cmd);
void	ft_getline_write(char *limiter, int *fd);

#endif
