/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:15:27 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/06 16:08:06 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
        size_t  i;

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, size_t start, size_t end)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (!str || start > end || start > ft_strlen(str))
		return (NULL);
	len = (end - start) + 1;
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[start] && start <= end)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strjoin(char **line, char **buffer)
{
	size_t	r;
	char	*new_line;

	if (!(*line) && !(*buffer))
		return (ERROR);
	if (!(*line))
	{
		*line = ft_substr(*buffer, 0, ft_strlen(*buffer) - 1);
		if (!(*line))
			return (ERROR);
		return (OK);
	}
	new_line = malloc(sizeof(char) * (ft_strlen(*line) + ft_strlen(*buffer) + 1));
	if (!new_line)
		return (ERROR);
	r = ft_strlcpy(new_line, *line, ft_strlen(*line) + 1);
	r = ft_strlcpy(&new_line[ft_strlen(new_line)], *buffer, ft_strlen(*buffer) + 1);
	free(*line);
	*line = new_line;
	(void) r;
	return (OK);
}

int	ft_index_of(char *str, char c)
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
