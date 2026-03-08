/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:52:10 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/08 12:52:41 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	t_gnl gnl;

	char *stash;
	stash = NULL;
	char *stash1 = "hello";
	char *stash2 = "hello\n";
	char *stash3 = "hello\ncomment ca va?\n";
	assert(!stash && stash1 && stash2 && stash3);
	init_gnl(&gnl);
	assert(process_stach_v2(&gnl, &stash) == READ);
	return (0);
}