/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:49:40 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/08 13:54:44 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_gnl(t_gnl *gnl)
{
	gnl->buffer[0] = '\0';
	gnl->b_read = 1;
	gnl->line[0] = NULL;
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
		*(gnl->line) = ft_substr(*stach, 0, new_ln_idx);
		sub = ft_substr(*stach, new_ln_idx + 1, ft_strlen(*stach) - 1);
		free(*stach);
		*stach = sub;
	}
	return (NO_READ);
}

/*
	case 1: stach == NULL; --> READ                 -> stach == NULL
	case 2: stach == "hello"; --> READ              -> stach == NULL
	case 3: stach == "hello\n"; --> NO_READ         -> stach == NULL
	case 4: stach == "hello\nworld\n"; --> NO_READ  -> stach == world\n

*/