/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_left_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvares <calvares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:27:13 by calvares          #+#    #+#             */
/*   Updated: 2025/11/28 17:13:43 by calvares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlen_nl(char *buff)
{
	int	len;

	if (!buff)
		return (0);
	len = 0;
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	if (buff[len] == '\n')
		len++;
	return (len);
}

int	has_newline(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*line_joint(char *line, char *buffer)
{
	char	*new_line;
	int		len_line;
	int		len_buff;
	int		i;
	int		j;

	len_line = strlen_nl(line);
	len_buff = strlen_nl(buffer);
	new_line = malloc(len_line + len_buff + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line && line[i] && i < len_line)
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] && j < len_buff)
		new_line[i++] = buffer[j++];
	new_line[i] = '\0';
	free (line);
	return (new_line);
}

void	set_buffer(char *buffer)
{
	int	i;
	int	j;

	if (!buffer)
		return ;
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		buffer[0] = '\0';
		return ;
	}
	i++;
	j = 0;
	while(buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
