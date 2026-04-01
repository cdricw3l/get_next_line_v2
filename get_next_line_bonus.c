/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:49:40 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/01 06:09:43 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	clean_gnl(t_gnl *gnl, int free_type)
{
	if (free_type == FREE_ALL)
	{
		if (gnl->line[0])
		{
			gnl->line[0] = NULL;
			free(gnl->line[0]);
		}
	}
	gnl->buffer = NULL;
	free(gnl->buffer);
	return (NO_READ);
}

static int	init_gnl(t_gnl *gnl, int fd)
{
	if (fd < 0 || fd > FD_MAX)
		return (0);
	gnl->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!gnl->buffer)
		return (0);
	gnl->b_read = 1;
	gnl->line[0] = NULL;
	return (1);
}

static int	process_stach_v2(t_gnl *gnl, char **stach, int new_ln_idx)
{
	char	*sub;

	if (!(*stach))
		return (READ);
	if (new_ln_idx < 0)
	{
		ft_strjoin(gnl->line, stach);
		*stach = NULL;
		free(*stach);
		return (READ);
	}
	if (new_ln_idx == (int)ft_strlen(*stach) - 1)
	{
		ft_strjoin(gnl->line, stach);
		*stach = NULL;
		free(*stach);
	}
	else if (new_ln_idx >= 0 && new_ln_idx < (int)ft_strlen(*stach) - 1)
	{
		*(gnl->line) = ft_substr(*stach, 0, new_ln_idx + 1);
		sub = ft_substr(*stach, new_ln_idx + 1, ft_strlen(*stach) - 1);
		free(*stach);
		*stach = sub;
	}
	return (NO_READ);
}

static int	process_buffer(t_gnl *gnl, char **stash, int idx_nl)
{
	char	*end_ln;

	if (idx_nl >= 0)
	{
		end_ln = ft_substr(gnl->buffer, 0, idx_nl + 1);
		if (ft_strjoin(gnl->line, &end_ln) == ERROR)
			return (clean_gnl(gnl, FREE_ALL));
		free(end_ln);
		*stash = ft_substr(gnl->buffer, idx_nl + 1, gnl->b_read - idx_nl);
		return (clean_gnl(gnl, FREE_BUFFER));
	}
	if (gnl->b_read == 0)
	{
		if (gnl->line[0] && ft_strlen(gnl->line[0]))
			return (clean_gnl(gnl, FREE_BUFFER));
		return (clean_gnl(gnl, FREE_ALL));
	}
	if (ft_strjoin(gnl->line, &gnl->buffer) == ERROR)
		return (clean_gnl(gnl, FREE_ALL));
	return (READ);
}

char	*get_next_line(int fd)
{
	t_gnl		gnl;
	static char	*stash[FD_MAX];

	if (!init_gnl(&gnl, fd))
		return (NULL);
	if (process_stach_v2(&gnl, &stash[fd], idx_of(stash[fd], 10)) == NO_READ)
	{
		gnl.buffer = NULL;
		free(gnl.buffer);
		return (gnl.line[0]);
	}
	while (idx_of(gnl.buffer, 10) < 0 && gnl.b_read > 0)
	{
		gnl.b_read = read(fd, gnl.buffer, BUFFER_SIZE);
		if (gnl.b_read < 0)
		{
			clean_gnl(&gnl, FREE_ALL);
			return (NULL);
		}
		gnl.buffer[gnl.b_read] = '\0';
		if (process_buffer(&gnl, &stash[fd], idx_of(gnl.buffer, 10)) == NO_READ)
			return (gnl.line[0]);
	}
	return (NULL);
}
