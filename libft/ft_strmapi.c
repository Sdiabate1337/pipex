/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:58:55 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/26 22:02:46 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	new_s = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_s)
		return (0);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
/*
int	main(void)
{
	char const	s[] = "je suis diabate";
	int	i = 0;
	char	*new = malloc(sizeof(char) * ft_strlen((char *)s));

	new = ft_strmapi(s, f);

	while (s[i])
	{
		printf("%c", new[i]);
		i++;
	}
}*/
