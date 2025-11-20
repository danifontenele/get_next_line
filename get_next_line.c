/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielalvares <danielalvares@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:49:49 by danielalvar       #+#    #+#             */
/*   Updated: 2025/11/20 01:58:29 by danielalvar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stash(char *stash_buffer)
{
	char	*new_stash;
	int		new_len;
	int		i;
	int		j;

	i = 0;
	while (stash_buffer[i] != '\n' && stash_buffer[i] != '\0')
		i++;
	if (stash_buffer[i] == '\0')
	{
		free (stash_buffer);
		return (NULL);
	}
	i++;
	new_len = ft_strlen(stash_buffer + i);
	new_stash = malloc(new_len + 1);
	if (!new_stash)
		return (free (stash_buffer), NULL);
	j = 0;
	while (stash_buffer[i])
		new_stash[j++] = stash_buffer[i++];
	new_stash[j] = '\0';
	free (stash_buffer);
	return (new_stash);
}

static char	*extract_line(char *stash_buffer)
{
	char *line;
	int	len;
	int	i;
	
	if (stash_buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (stash_buffer[i] != '\n' && stash_buffer[i] != '\0')
		i++;
	if (stash_buffer[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash_buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*read_file(char *stash_buffer, int fd)
{
	ssize_t	nbytes;
	char	*get_buffer;

	get_buffer = malloc(BUFFER_SIZE + 1);
	nbytes = 1;
	while (!ft_strchr(stash_buffer, '\n') && nbytes > 0)
	{
		nbytes = read(fd, get_buffer , BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(get_buffer);
			return (NULL);
		}
		get_buffer[nbytes] = '\0';
 		stash_buffer = ft_strjoin(stash_buffer, get_buffer);
 		if (!stash_buffer)
			return (free(get_buffer), NULL);
	}
	free (get_buffer);
	return (stash_buffer);
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
	static	char	*stash_buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash_buffer)
		stash_buffer = calloc(1, 1);
	stash_buffer = read_file(stash_buffer, fd);
	if (!stash_buffer)
		return (NULL);
	line = extract_line(stash_buffer);
	if (!line)
	{
		free (stash_buffer);
		stash_buffer = NULL;
		return (NULL);
	}
	stash_buffer = update_stash(stash_buffer);
	return (line);
}

int	main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("error on opening file!\n"));
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	close(fd);
	return (0);
}