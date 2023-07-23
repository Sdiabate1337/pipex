/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:30:23 by sdiabate          #+#    #+#             */
/*   Updated: 2023/07/23 17:30:27 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_getline_write(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	while (get_line(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
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
