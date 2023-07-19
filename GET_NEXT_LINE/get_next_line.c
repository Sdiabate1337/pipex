/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:56:51 by sdiabate          #+#    #+#             */
/*   Updated: 2023/05/02 17:08:11 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_reserve(int fd, char *reserve)
{
	int		lue;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	lue = 1;
	while (!ft_strchr_nc(reserve, '\n') && lue > 0)
	{
		lue = (int)read(fd, buff, BUFFER_SIZE);
		if (lue == -1)
		{
			free(buff);
			free(reserve);
			return (NULL);
		}
		buff[lue] = '\0';
		reserve = ft_free_join(reserve, buff);
	}
	free(buff);
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = ft_read_reserve(fd, reserve);
	if (!reserve)
		return (NULL);
	line = ft_extract_line(reserve);
	reserve = ft_clean_reserve(reserve);
	return (line);
}
