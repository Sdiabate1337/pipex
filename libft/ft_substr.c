/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:04:53 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/28 22:10:39 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (!*s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		str = malloc(sizeof(char) * (ft_strlen((char *)s) - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	str[j] = 0;
	return (str);
}

/*
int	main(void)
{
	printf("%s", ft_substr(NULL, 0, 0));
		
}*/
