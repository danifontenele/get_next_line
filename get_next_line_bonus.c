/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvares <calvares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:48:20 by calvares          #+#    #+#             */
/*   Updated: 2025/11/28 23:35:26 by calvares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				return (line);
			buffer[fd][bytes_read] = '\0';
		}
		line = line_joint(line, buffer[fd]);
		set_buffer(buffer[fd]);
		if (has_newline(line))
			return (line);
		buffer[fd][0] = '\0';
	}
}

/* int	main(void)
{
	int	fd1;
	int	fd2;
	char *line1;
	char *line2;

	fd1 = open("txt.1", O_RDONLY);
	fd2 = open("txt.2", O_RDONLY);

	line1 = get_next_line(fd1);
	printf("%s", line1);
	free (line1);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free (line2);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free (line1);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free (line2);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free (line1);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free (line2);
	close (fd1);
	close (fd2);

	return (0);
} */