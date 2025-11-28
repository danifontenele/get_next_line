/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvares <calvares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:24:53 by calvares          #+#    #+#             */
/*   Updated: 2025/11/28 18:43:56 by calvares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return(free(line), NULL);
			else if (bytes_read == 0)
				return (line);
			buffer[bytes_read] = '\0';
		}
		line = line_joint(line, buffer);
		if (has_newline(line))
			return (set_buffer(buffer), line);
		set_buffer(buffer);
	}
}

/* int main(void)
{
	char *line;
	int fd;

	fd = open("pseudocode.txt", O_RDONLY);
	if (fd < 0)
		printf("can't open the file");
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	return (0);
} */