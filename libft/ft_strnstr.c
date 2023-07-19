/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:01:09 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/27 02:19:07 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!str && !len)
		return (0);
	if (needle[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (i + j < len && str[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *s;
	s = ft_strnstr("", NULL, 0);
	printf("%s", s);
}*/
