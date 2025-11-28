/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvares <calvares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:25:22 by calvares          #+#    #+#             */
/*   Updated: 2025/11/28 17:19:45 by calvares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"
# include "stdint.h"
# include "stdlib.h"

char	*get_next_line(int fd);
int	    strlen_nl(char *buffer);
int	    has_newline(char *buffer);
char	*line_joint(char *line, char *buffer);
void	set_buffer(char *buffer);

#endif