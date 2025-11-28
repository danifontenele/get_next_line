/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvares <calvares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:48:25 by calvares          #+#    #+#             */
/*   Updated: 2025/11/28 22:53:31 by calvares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	strlen_nl(char *buff)
{
	int	len;

	if (!buff)
		return (0);
	len = 0;
	while (buff[len] != '\0' && buff[len] != '\n')
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
	int		line_len;
	int		buffer_len;
	int		i;
	int		j;
	char	*new_line;

	line_len = strlen_nl(line);
	buffer_len = strlen_nl(buffer);
	new_line = malloc(line_len + buffer_len + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line && line[i] && i < line_len)
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] && j < buffer_len)
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		buffer[0] = '\0';
		return ;
	}
	i++;
	j = 0;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
