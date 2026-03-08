#include "../get_next_line.h"
#include <assert.h>
#include <string.h>

int		process_stach_v2(t_gnl *gnl, char **stach);
void	init_gnl(t_gnl *gnl);

int ft_strjoin_assertions()
{
	char *line;
	char *buffer;

	printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
	line = NULL;
	buffer = NULL;
	assert(ft_strjoin(&line, &buffer) == ERROR);
	buffer = strdup("hello world");
	assert(ft_strjoin(&line, &buffer) == OK);
	assert(!strncmp(buffer, line, strlen(buffer)));
	free(line);
	line = strdup("hello paris, ");
	assert(ft_strjoin(&line, &buffer) == OK);
	assert(!strncmp("hello paris, hello world", line, strlen(line)));
	free(buffer);
	buffer = strdup(" endddddd\n");
	assert(ft_strjoin(&line, &buffer) == OK);
	assert(!strncmp("hello paris, hello world endddddd\n", line, strlen(line)));
	free(buffer);
	free(line);
	line = NULL;
	buffer = strdup("");
	assert(ft_strjoin(&line, &buffer) == OK);
	assert(strlen(line) == 0);
	assert(!strncmp(buffer, line, strlen(line)));
	free(buffer);
	free(line);
	printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
	return (0);
}

void	ft_process_stach_assertions(void)
{
	t_gnl	gnl;
	char	*stach;

	printf( "\033[33m" "\nTEST: %s\n" "\033[0m", __FUNCTION__);
	init_gnl(&gnl);
	stach  = NULL;
	assert(process_stach_v2(&gnl, &stach) == READ && stach == NULL && gnl.line[0] == NULL);
	stach = strdup("hello_world");
	assert(process_stach_v2(&gnl, &stach) == READ && stach == NULL && !strncmp(gnl.line[0], "hello_world", strlen(gnl.line[0])));
	stach = strdup("hello_world\nhello_berlin");
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	assert(process_stach_v2(&gnl, &stach) == NO_READ && !strncmp(stach, "hello_berlin", strlen(stach)) && !strncmp(gnl.line[0], "hello_world\n", strlen(gnl.line[0])));
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	assert(process_stach_v2(&gnl, &stach) == READ && stach == NULL && !strncmp(gnl.line[0], "hello_berlin", strlen(gnl.line[0])));
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	stach = strdup("hello_world\nhello_berlin\n");
	assert(process_stach_v2(&gnl, &stach) == NO_READ && !strncmp(stach, "hello_berlin\n", strlen(stach)) && !strncmp(gnl.line[0], "hello_world\n", strlen(gnl.line[0])));
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	assert(process_stach_v2(&gnl, &stach) == NO_READ && stach == NULL && !strncmp(gnl.line[0], "hello_berlin\n", strlen(gnl.line[0])));
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	stach = strdup("");
	assert(process_stach_v2(&gnl, &stach) == READ && stach == NULL && !strncmp(gnl.line[0], "", strlen(gnl.line[0])));
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	stach = strdup("\n");
	assert(idx_of(stach, 10) >= 0 && idx_of(stach, 10) == (int)ft_strlen(stach) - 1);
	assert(process_stach_v2(&gnl, &stach) == NO_READ && stach == NULL && !strncmp(gnl.line[0], "\n", strlen(gnl.line[0])));
	assert(stach == NULL);
	free(gnl.line[0]);
	gnl.line[0] = NULL;
	stach = strdup("\n\n\n");
	int i = 0;
	while (stach)
	{
		printf("TEST %d\n", i++);
		int r = process_stach_v2(&gnl, &stach);
		assert(r == NO_READ);
		free(gnl.line[0]);
		gnl.line[0] = NULL;
		(void)r;

	}
	assert(stach == NULL);
	printf( "\033[32m" "TEST: %s OK!\n" "\033[0m", __FUNCTION__);
}

int main(void)
{
	ft_strjoin_assertions();
	ft_process_stach_assertions();
	return (0);
}
