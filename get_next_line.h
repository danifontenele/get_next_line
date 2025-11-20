/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielalvares <danielalvares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:03:14 by danielalvar       #+#    #+#             */
/*   Updated: 2025/11/20 01:38:38 by danielalvar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"
# include "stdint.h"
# include "stdlib.h"

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb,size_t size);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif