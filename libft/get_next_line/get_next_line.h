/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:54 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 18:55:35 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	gnl_strlcpy(char *dst, const char *src, size_t dstlen);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *str1, char const *str2);
char	*gnl_substr(char const *s, size_t start, size_t len);
char	*readline(int fd, char *buffer, char *line);
char	*get_next_line(int fd);

#endif