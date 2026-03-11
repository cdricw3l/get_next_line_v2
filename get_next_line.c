/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:49:40 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 02:29:44 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*clean_gnl(t_gnl *gnl)
{
	free(gnl->buffer);
	gnl->buffer = NULL;
	if (gnl->line[0])
	{
		free(gnl->line[0]);
		gnl->line[0] = NULL;
	}
	return (NULL);
}

int	init_gnl(t_gnl *gnl)
{
	gnl->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!gnl->buffer)
		return (0);
	gnl->b_read = 1;
	gnl->line[0] = NULL;
	return (1);
}

int	process_stach_v2(t_gnl *gnl, char **stach, int new_ln_idx)
{
	char	*sub;

	if (!(*stach))
		return (READ);
	if (new_ln_idx < 0)
	{
		ft_strjoin(gnl->line, stach);
		free(*stach);
		*stach = NULL;
		return (READ);
	}
	if (new_ln_idx == (int)ft_strlen(*stach) - 1)
	{
		ft_strjoin(gnl->line, stach);
		free(*stach);
		*stach = NULL;
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



char	*get_next_line(int fd)
{
	int			r;
	t_gnl		gnl;
	char 		*end;
	static char	*stash;

	if (!init_gnl(&gnl))
		return (NULL);
	if (process_stach_v2(&gnl, &stash, idx_of(stash, 10)) == NO_READ)
	{
		free(gnl.buffer);
		return (gnl.line[0]);
	}
	while (idx_of(gnl.buffer, 10) < 0 && gnl.b_read > 0)
	{
		gnl.b_read = read(fd, gnl.buffer, BUFFER_SIZE - 1);
		if (gnl.b_read < 0)
			return (clean_gnl(&gnl));
		gnl.buffer[gnl.b_read] = '\0';
		if (idx_of(gnl.buffer, 10) >= 0)
		{
			end = ft_substr(gnl.buffer, 0, idx_of(gnl.buffer, 10) + 1);
			r = ft_strjoin(gnl.line, &end);
			if (r == ERROR)
				return (NULL);
			free(end);
			stash = ft_substr(gnl.buffer, idx_of(gnl.buffer, 10) + 1, ft_strlen(gnl.buffer) - idx_of(gnl.buffer, 10));
		}
		else
		{
			
			if (gnl.b_read == 0)
			{
				free(gnl.buffer);
				gnl.buffer = NULL;
			}
			else
			{
				r = ft_strjoin(gnl.line, &gnl.buffer);
				if (r == ERROR)
					return (NULL);
			}
		}
	}
	free(gnl.buffer);
	return (gnl.line[0]);
}

/*
	case 1: stach == NULL; --> READ                 -> stach == NULL
	case 2: stach == "hello"; --> READ              -> stach == NULL
	case 3: stach == "hello\n"; --> NO_READ         -> stach == NULL
	case 4: stach == "hello\nworld\n"; --> NO_READ  -> stach == world\n

*/