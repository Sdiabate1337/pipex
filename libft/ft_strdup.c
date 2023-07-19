/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:49:40 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/26 22:53:44 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen((const char *)src);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	printf("%s", ft_strdup("\0"));
	printf("%s", strdup("\0"));
	printf("%s", strchr(NULL));
}*/
