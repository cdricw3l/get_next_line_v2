/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:49:40 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 20:11:21 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	clean_gnl(t_gnl *gnl)
{
	free(gnl->buffer);
	gnl->buffer = NULL;
	if (gnl->line[0])
	{
		free(gnl->line[0]);
		gnl->line[0] = NULL;
	}
	return (NO_READ);
}

static int	init_gnl(t_gnl *gnl, int fd)
{
	gnl->fd = fd;
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

	if (!stach[gnl->fd])
		return (READ);
	if (new_ln_idx < 0)
	{
		ft_strjoin(gnl->line, &stach[gnl->fd]);
		free(stach[gnl->fd]);
		stach[gnl->fd] = NULL;
		return (READ);
	}
	if (new_ln_idx == (int)ft_strlen(*stach) - 1)
	{
		ft_strjoin(gnl->line, &stach[gnl->fd]);
		free(stach[gnl->fd]);
		stach[gnl->fd] = NULL;
	}
	else if (new_ln_idx >= 0 && new_ln_idx < (int)ft_strlen(*stach) - 1)
	{
		*(gnl->line) = ft_substr(stach[gnl->fd], 0, new_ln_idx + 1);
		sub = ft_substr(stach[gnl->fd], new_ln_idx + 1, ft_strlen(*stach) - 1);
		free(stach[gnl->fd]);
		stach[gnl->fd] = sub;
	}
	return (NO_READ);
}

static int	process_buffer(t_gnl *gnl, char **stash, int nl_idx)
{
	char	*end;

	if (nl_idx >= 0)
	{
		end = ft_substr(gnl->buffer, 0, nl_idx + 1);
		if (ft_strjoin(gnl->line, &end) == ERROR)
			return (clean_gnl(gnl));
		free(end);
		stash[gnl->fd] = ft_substr(gnl->buffer,
				nl_idx + 1, gnl->b_read - nl_idx);
		free(gnl->buffer);
		return (NO_READ);
	}
	if (gnl->b_read == 0)
	{
		if (gnl->line[0])
		{
			free(gnl->buffer);
			return (NO_READ);
		}
		return (clean_gnl(gnl));
	}
	if (ft_strjoin(gnl->line, &gnl->buffer) == ERROR)
		return (clean_gnl(gnl));
	return (READ);
}

char	*get_next_line(int fd)
{
	t_gnl		gnl;
	static char	*stash;

	if (!init_gnl(&gnl, fd))
		return (NULL);
	if (process_stach_v2(&gnl, &stash, idx_of(stash, 10)) == NO_READ)
	{
		free(gnl.buffer);
		return (gnl.line[0]);
	}
	while (idx_of(gnl.buffer, 10) < 0 && gnl.b_read > 0)
	{
		gnl.b_read = read(fd, gnl.buffer, BUFFER_SIZE);
		if (gnl.b_read < 0)
		{
			clean_gnl(&gnl);
			return (NULL);
		}
		gnl.buffer[gnl.b_read] = '\0';
		if (process_buffer(&gnl, &stash, idx_of(gnl.buffer, 10)) == NO_READ)
			return (gnl.line[0]);
	}
	return (NULL);
}
