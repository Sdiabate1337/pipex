/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:28:48 by sdiabate          #+#    #+#             */
/*   Updated: 2023/01/22 15:17:02 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!src && !dest)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	while (n--)
		d[n] = s[n];
	return ((void *)d);
}
