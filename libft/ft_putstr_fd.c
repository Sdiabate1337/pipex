/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:34:06 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/26 17:45:02 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*
int	main(void)
{
	ft_putstr_fd("\0", -1);	
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd("hello", 1);
}*/
