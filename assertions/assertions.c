#include "../get_next_line.h"
#include <assert.h>
#include <string.h>

int ft_strjoin_assertions()
{
	char *line;
	char *buffer;

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
	return (0);
}

int main(void)
{
	ft_strjoin_assertions();
	return (0);
}
