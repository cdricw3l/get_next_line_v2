/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 08:15:21 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/01 05:52:38 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd = open("gnlTester/files/42_with_nl", O_RDONLY);
    
    char *line;

    
    while((line = get_next_line(fd)) != NULL)
    {
        printf("line: %s", line);
    }
    line = get_next_line(fd);
    assert(!line);
    return (0);
}

