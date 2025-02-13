/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:33:35 by renrodri          #+#    #+#             */
/*   Updated: 2025/02/12 23:12:07 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// reads the fd and returns the temp buffer with the current data
char	*read_fd(int fd, char *temp)
// reads the fd and returns the temp buffer with the current data
char	*read_fd(int fd, char *temp)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(temp, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		temp = ft_strjoin(temp, buffer);
	}
	free (buffer);
	return (temp);
	return (temp);
}

// extracts and returns the current line from the temp buffer
char	*get_current_line(char *temp)
// extracts and returns the current line from the temp buffer
char	*get_current_line(char *temp)
{
	int		i;
	char	*string;

	i = 0;
	if (!temp[i])
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
	while (temp[i] && temp[i] != '\n')
		i++;
	string = ft_substr(temp, 0, i + (temp[i] == '\n'));
	string = ft_substr(temp, 0, i + (temp[i] == '\n'));
	return (string);
}

// returns the remaining string after the current line and frees the old buffer
char	*string_to_add(char *temp)
// returns the remaining string after the current line and frees the old buffer
char	*string_to_add(char *temp)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	if (!temp[i])
	{
		free(temp);
		free(temp);
		return (NULL);
	}
	string = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	string = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!string)
		return (NULL);
	i++;
	while (temp[i])
		string[j++] = temp[i++];
	while (temp[i])
		string[j++] = temp[i++];
	string[j] = '\0';
	free (temp);
	free (temp);
	return (string);
}

// returns the next line from the file descriptor
// returns the next line from the file descriptor
char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_fd(fd, temp);
	if (!temp)
	temp = read_fd(fd, temp);
	if (!temp)
		return (NULL);
	line = get_current_line(temp);
	temp = string_to_add(temp);
	line = get_current_line(temp);
	temp = string_to_add(temp);
	return (line);
}
