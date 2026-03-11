/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:52:10 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 20:14:34 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	get_lines(void)
{
	int		fd_1;
	char	*line;

	fd_1 = open("files/numbers.dict_1", O_RDONLY);
	if (fd_1 < 0)
	{
		printf("Open Error\n");
		return ;
	}
	while ((line = get_next_line(fd_1)))
	{
		if (line)
			printf("%s", line);
		free(line);
	}
}

int	main(void)
{
	get_lines();
	return (0);
}
