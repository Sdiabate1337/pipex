/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:46:41 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/26 18:09:57 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//#include <string.h>
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}
/*
int	main(void)
{
	printf("%s", ft_strchr(NULL, 'w'));
	printf("%s", strchr(NULL, 'w'));
}*/
