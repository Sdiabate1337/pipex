/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:52:44 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/27 00:38:13 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	i = -1;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (join)
	{
		while (s1[++i])
			join[i] = s1[i];
		i = -1;
		while (s2[++i])
			join[s1_len + i] = s2[i];
		join[s1_len + i] = '\0';
		return (join);
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", ft_strjoin(NULL, NULL));
}*/
