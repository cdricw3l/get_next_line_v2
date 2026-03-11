/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:46:18 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/11 19:59:39 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <assert.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define READ		1
# define NO_READ	0
# define ERROR 		-1
# define OK 		1

typedef struct s_gnl
{
	int		fd;
	size_t	b_read;
	char	*line[1];
	char	*stach[FD_SETSIZE];
	char	*buffer;

}	t_gnl;

//UTILS

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_strjoin(char **line, char **buffer);
int		idx_of(char *str, char c);
size_t	ft_strlen(const char *s);

#endif