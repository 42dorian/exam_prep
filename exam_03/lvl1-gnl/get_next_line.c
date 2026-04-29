#include "get_next_line.h"

int has_newline(char *s)
{
	int i;

	i = 0;
	if (!s)
		return -1;
	while (s[i])
	{
		if (s[i] == '\n')
			return i;
		i++;
	}
	return -1;
}

char *get_next_line(int fd) {
    static char buffer[10000];
	static int cursor = 0;
	static int end_line = 0;
	char *line;
	int r = -1, i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1024);
	if(!line)
		return NULL;
	while (1)
	{
		r = read(fd, buffer + end_line, BUFFER_SIZE);
		if (r == 0)
			break;
		end_line += r;
		buffer[end_line] = 0;
		if (has_newline(&buffer[cursor]) >= 0)
			break;
	}
	while (buffer[cursor])
	{
		line[i] = buffer[cursor];
		i++;
		if (buffer[cursor++] == '\n')
			break;
	}
	line[i] = 0;
	if (!line || *line == 0)
		return (free(line), NULL);
    return line;
}


#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
