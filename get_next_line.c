/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielalvares <danielalvares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:49:49 by danielalvar       #+#    #+#             */
/*   Updated: 2025/11/25 16:36:25 by danielalvar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *left_c)
{
	size_t	i;
	int		len;
	char	*line;

	if (!left_c || left_c[0] == '\0')
		return (NULL);
	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (left_c[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = ft_substr(left_c, 0, len);
	return (line);
}

static char	*extract_rest(char *left_c)
{
	size_t	i;
	char	*rest;

	if (!left_c)
		return (NULL);
	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (left_c[i] == '\0')
	{
		free (left_c);
		return (NULL);
	}
	rest = ft_substr(left_c, i + 1, ft_strlen(left_c) - i - 1);
	free (left_c);
	return (rest);
}

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	nbytes;
	char	*tmp;

	nbytes = 1;
	if (!left_c)
		left_c = ft_strdup("");
	while (nbytes > 0 && !ft_strchr(left_c, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1) // Deu erro, libera o buffer que resta
		{
			free (left_c);
			return (NULL);
		}
		if (nbytes == 0) // Leu tudo
			break ;
		buffer[nbytes] = '\0'; // finish the string
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer); // Cola o que restou no inicio do buffer
		free (tmp);
	}
	return (left_c);
}

/**
 * @brief This functions returns a line read from a
 * file descriptor and from the standard input.
 * 
 * The return should be followed by a newline, except when
 * the end of the file is reached and there is no new line there.
 * 
 * @param fd The file descriptor to read from
 * @return Read line: Correct behavior. NULL if there is
 * nothing else to read or an error occurred.
 */
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*left_c;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	left_c = fill_line_buffer(fd, left_c, buffer);
	if (!left_c)
	{
		free (buffer);
		return (NULL);
	}
	free (buffer);
	line = extract_line(left_c);
	left_c = extract_rest(left_c);
	return (line);
}

/* int	main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("error on opening file!\n"));
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
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	close(fd);
	printf("%s", line);
	free (line);
	close(fd);
	printf("%s", line);
	free (line);
	close(fd);
	printf("%s", line);
	free (line);
	close(fd);
	return (0);
} */