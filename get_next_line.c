/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:49:40 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/06 15:10:08 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_gnl(t_gnl *gnl)
{
	gnl->buffer[0] = '\0';
	gnl->b_read = 1;
	gnl->line[0] = NULL;
}

int	process_stach_v2(t_gnl *gnl, char **stach)
{
	int	r;

	if (!(*stach))
		return (READ);
	if (idx_of(*stach, 10) < 0)
	{
		ft_strjoin(gnl->line, *stach);
		free(*stach);
		return (READ);
	}
	if (idx_of(*stach, 10) && idx_of(*stach, 10) == ft_strlen(*stach) - 1)
	{
		ft_strjoin(gnl->line, *stach);
		free(*stach);
	}
	else if (idx_of(*stach, 10) && idx_of(*stach, 10) < ft_strlen(*stach) - 1)
	{
		*(gnl->line) = ft_substr(*stach, 0, idx_of(*stach, 10));
		free(*stach);
		*stach = ft_substr(*stach, idx_of(*stach, 10) + 1,
				ft_strlen(*stach) - 1);
	}
	return (NO_READ);
}

// int main(void)
// {
// 	t_gnl gnl;

// 	char *stash;
// 	stash = NULL;
// 	char *stash1 = "hello";
// 	char *stash2 = "hello\n";
// 	char *stash3 = "hello\ncomment ca va?\n";
// 	assert(!stash && stash1 && stash2 && stash3);
// 	init_gnl(&gnl);
// 	assert(process_stach_v2(&gnl, &stash) == READ);
// 	return (0);
// }

/*
	case 1: stach == NULL; --> READ                 -> stach == NULL
	case 2: stach == "hello"; --> READ              -> stach == NULL
	case 3: stach == "hello\n"; --> NO_READ         -> stach == NULL
	case 4: stach == "hello\nworld\n"; --> NO_READ  -> stach == world\n

*/