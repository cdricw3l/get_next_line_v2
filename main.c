/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:52:10 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 01:05:55 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>


int main(void)
{
	int		fd;
	char	*line;

	fd = open("files/numbers.dict_1", O_RDONLY);
	if (fd < 0)
	{
		printf("Open Error\n");
		return (1);
	}

	while((line = get_next_line(fd)))
	{
		if (line)
			printf("%s", line);
		free(line);
	}
	
	
	return (0);
}

// int	process_stach_v2(t_gnl *gnl, char **stach, int new_ln_idx);
// int	init_gnl(t_gnl *gnl);

// int main(void)
// {
// 	t_gnl gnl;
// 	int r;
// 	init_gnl(&gnl);
// 	char *str = strdup("hello\nberlin comment tu va\n moi je vais bien\n ");

// 	assert(idx_of(str, 10) == 5);
// 	r = process_stach_v2(&gnl, &str, idx_of(str, 10));
// 	assert(r == NO_READ);
// 	assert(!strncmp(gnl.line[0], "hello\n", strlen(gnl.line[0])));
// 	assert(!strncmp(str, "berlin comment tu va\n moi je vais bien\n ", strlen(str)));
// 	free(gnl.line[0]);
// 	gnl.line[0] = NULL;
// 	r = process_stach_v2(&gnl, &str, idx_of(str, 10));
// 	assert(r == NO_READ);
// 	assert(!strncmp(gnl.line[0], "berlin comment tu va\n", strlen(gnl.line[0])));
// 	assert(!strncmp(str, " moi je vais bien\n ", strlen(str)));
// 	free(gnl.line[0]);
// 	gnl.line[0] = NULL;
// 	r = process_stach_v2(&gnl, &str, idx_of(str, 10));
// 	assert(r == NO_READ);
// 	assert(!strncmp(gnl.line[0], " moi je vais bien\n", strlen(gnl.line[0])));
// 	assert(!strncmp(str, " ", strlen(str)));
// 	free(gnl.line[0]);
// 	gnl.line[0] = NULL;
// 	r = process_stach_v2(&gnl, &str, idx_of(str, 10));
// 	assert(r == READ);
// 	assert(!strncmp(gnl.line[0], " ", strlen(gnl.line[0])));
// 	assert(!str);
// 	return (0);
// }