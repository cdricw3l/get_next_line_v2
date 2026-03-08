#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 10
#endif

#define READ    1
#define NO_READ 0
#define ERROR 	-1
#define OK 		1

typedef struct s_gnl
{
	size_t b_read;
	char *line[1];
	char *stach[1];
	char buffer[BUFFER_SIZE];

} t_gnl;

//UTILS

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_substr(char *str, size_t start, size_t end);
int		ft_strjoin(char **line, char **buffer);
int		idx_of(char *str, char c);
char	*ft_strdup(const char *s1);

// void assertion_substr()
// {
// 	char *s1 = "hello_world";
// 	char *sub;

// 	sub = ft_substr(s1, 2, 5);
// 	assert(!strncmp(sub, "llo_", ft_strlen(sub)));
// 	free(sub);
// 	sub = ft_substr(s1, 0, 50);
// 	assert(!strncmp(sub, "hello_world", ft_strlen(sub)));
// 	free(sub);
// 	sub = ft_substr(s1, 6, 7);
// 	assert(!strncmp(sub, "wo", ft_strlen(sub)));
// 	free(sub);
// 	sub = ft_substr(s1, 6, 6);
// 	assert(!strncmp(sub, "w", ft_strlen(sub)));
// 	free(sub);
// 	sub = ft_substr(s1, 6, 0);
// 	assert(!sub);
// 	sub = ft_substr(NULL, 0, 5);
// 	assert(!sub);
// }

#endif