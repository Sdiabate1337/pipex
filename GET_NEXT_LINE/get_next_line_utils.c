/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:57:19 by sdiabate          #+#    #+#             */
/*   Updated: 2023/05/02 17:14:35 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nc(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr_nc(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen_nc(str)]);
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

char	*ft_free_join(char *reserve, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!reserve)
	{
		reserve = (char *)malloc(1 * sizeof(char));
		reserve[0] = '\0';
	}
	if (!reserve && !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_nc(reserve) + ft_strlen_nc(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (reserve)
		while (reserve[++i] != '\0')
			str[i] = reserve[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_nc(reserve) + ft_strlen_nc(buffer)] = '\0';
	free(reserve);
	return (str);
}
 
char	*ft_extract_line(char *reserve)
{
	int		i;
	char	*line;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_reserve(char *reserve)
{
	char	*tokeep;
	int		i;
	int		j;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	tokeep = (char *)malloc((ft_strlen_nc(reserve) - i + 1) * sizeof(char));
	if (!tokeep)
		return (NULL);
	i++;
	j = 0;
	while (reserve[i])
		tokeep[j++] = reserve[i++];
	tokeep[j] = '\0';
	free(reserve);
	return (tokeep);
}
