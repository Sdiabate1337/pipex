/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiabate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:57:06 by sdiabate          #+#    #+#             */
/*   Updated: 2023/05/02 13:57:11 by sdiabate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

size_t	ft_strlen_nc(char *c);
char	*ft_strchr_nc(char *str, int c);
char	*ft_free_join(char *s1, char *s2);
char	*ft_clean_reserve(char *reserve);
char	*ft_extract_line(char *reserve);
char	*get_next_line(int fd);
char	*ft_read_reserve(int fd, char *reserve);

#endif
