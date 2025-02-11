/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:53:39 by renrodri          #+#    #+#             */
/*   Updated: 2025/02/11 18:44:52 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// returns the lenght of the given string
size_t	ft_strlen(char const *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

// finds the 1st occurrence of a character in a string and returns its pointer
char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	*string_to_search_in;

	if (!s || !c)
		return (NULL);
	i = 0;
	string_to_search_in = (char *)s;
	while (string_to_search_in[i])
	{
		if (string_to_search_in[i] == (char) c)
			return (&string_to_search_in[i]);
		i++;
	}
	return (0);
}

// joins two strings and returns the new concatenated string
char	*ft_strjoin(char *str1, char *str2)
{
	char		*concat_string;
	size_t		i;
	size_t		j;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = '\0';
	}
	concat_string = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!concat_string)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		concat_string[i] = str1[i];
		i++;
	}
	while (str2[j])
		concat_string[i++] = str2[j++];
	concat_string[i] = '\0';
	free(str1);
	return (concat_string);
}

// returns a substring of the given string
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (!s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
