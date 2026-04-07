/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:15:27 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/07 15:34:58 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlcpy_custom(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen_custom(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr_custom(char const *s, unsigned int start, size_t len)
{
	size_t	bytes_cpy;
	size_t	src_len;
	char	*new_str;

	if (!s)
		return (NULL);
	src_len = ft_strlen_custom(s);
	if (start > src_len)
		return (NULL);
	if (len > src_len)
		len = src_len;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	bytes_cpy = 0;
	while (s[start] && bytes_cpy < len)
		new_str[bytes_cpy++] = s[start++];
	new_str[bytes_cpy] = '\0';
	return (new_str);
}

int	ft_strjoin_custom(char **line, char **buffer)
{
	char	*new_line;

	if (!(*line) && !(*buffer))
		return (ERROR);
	if (!(*line))
	{
		*line = ft_substr_custom(*buffer, 0, ft_strlen_custom(*buffer));
		if (!(*line))
			return (ERROR);
		return (OK);
	}
	new_line = malloc(sizeof(char)
			*(ft_strlen_custom(*line) + ft_strlen_custom(*buffer) + 1));
	if (!new_line)
		return (ERROR);
	ft_strlcpy_custom(new_line, *line, ft_strlen_custom(*line) + 1);
	ft_strlcpy_custom(&new_line[ft_strlen_custom(new_line)],
		*buffer, ft_strlen_custom(*buffer) + 1);
	free(*line);
	*line = new_line;
	return (OK);
}

int	idx_of(char *str, char c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
