/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:58:07 by renrodri          #+#    #+#             */
/*   Updated: 2024/11/20 14:52:55 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*string_to_add(char *stash);
char	*get_current_line(char *stash);
char	*read_fd(int fd, char *stash);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_endl(char *buffer);
size_t	ft_strlen(char const *string);

#endif