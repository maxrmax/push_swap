/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:56 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 15:14:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	gnl_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstlen - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*gnl_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = gnl_strlen(s) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	gnl_strlcpy(dst, s, len);
	return (dst);
}

char	*gnl_strjoin(char *str1, char const *str2)
{
	char	*newstr;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1 || !str2)
		return (NULL);
	str1_len = gnl_strlen(str1);
	str2_len = gnl_strlen(str2);
	newstr = malloc(str1_len + str2_len + 1);
	if (!newstr)
		return (NULL);
	gnl_strlcpy(newstr, str1, str1_len + 1);
	gnl_strlcpy((newstr + str1_len), str2, str2_len + 1);
	return (newstr);
}

char	*gnl_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (start >= gnl_strlen(s) || start < 0)
		return (gnl_strdup(""));
	if (len > gnl_strlen(s) - start)
		len = gnl_strlen(s) - start;
	while (i < start)
		i++;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	gnl_strlcpy(substr, &s[i], len + 1);
	return (substr);
}
