/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielalvares <danielalvares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:03:14 by danielalvar       #+#    #+#             */
/*   Updated: 2025/11/25 13:27:18 by danielalvar      ###   ########.fr       */
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
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif