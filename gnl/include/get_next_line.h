/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:54:55 by cdric.b           #+#    #+#             */
/*   Updated: 2026/04/07 15:32:29 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <assert.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# define READ    		1
# define NO_READ		0
# define ERROR			-1
# define OK				1
# define FREE_BUFFER	0
# define FREE_ALL		1
# define FD_MAX			1048575

typedef struct s_gnl
{
	int		b_read;
	char	*line[1];
	char	*stach[1];
	char	*buffer;

}	t_gnl;

//UTILS

char	*get_next_line(int fd);
size_t	ft_strlen_custom(const char *s);
int		idx_of(char *str, char c);
int		ft_strjoin_custom(char **line, char **buffer);
char	*ft_substr_custom(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif