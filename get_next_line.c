/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:33:35 by renrodri          #+#    #+#             */
/*   Updated: 2025/01/03 15:47:57 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lê o arquivo e retorna o stash concatenado com o buffer atual
char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

// Pega a linha atual até o \n ou até o nulo
char	*get_current_line(char *stash)
{
	int		i;
	char	*string;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	string = ft_substr(stash, 0, i + (stash[i] == '\n'));
	return (string);
}

char	*string_to_add(char *stash)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	string = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!string)
		return (NULL);
	i++;
	while (stash[i])
		string[j++] = stash[i++];
	string[j] = '\0';
	free (stash);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_fd(fd, stash);
	if (!stash)
		return (NULL);
	line = get_current_line(stash);
	stash = string_to_add(stash);
	return (line);
}
