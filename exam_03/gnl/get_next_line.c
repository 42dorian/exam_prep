#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	static int	cursor = 0;
	static int	b_len = -1;
	int			r = 1, i = 0, end_line = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || cursor == b_len)
		return (free(buffer), NULL);
	if (!buffer)
		buffer = malloc(1024);
	while (r > 0)
	{
		r = read(fd, buffer + end_line, BUFFER_SIZE);
		if (r == 0)
			break ;
		end_line += r;
		buffer[end_line] = '\0';
		b_len = end_line;
	}
	line = malloc(1024);
	while (cursor < b_len)
	{
		line[i] = buffer[cursor];
		i++;
		if (buffer[cursor++] == '\n')
			break;
	}
	line[i] = '\0';
	if (!line || *line == 0)
		return (free(line), free(buffer), NULL);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
