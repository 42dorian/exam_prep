#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		r;
	char	curr;
	int		i;

	i = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	r = read(fd, &curr, 1);
	if (r <= 0)
		return (NULL);
	line = malloc(1024);
	while (r > 0)
	{
		line[i] = curr;
		i++;
		if (curr == '\n')
			break ;
		r = read(fd, &curr, 1);
		if (r <= 0)
			return (line);
	}
	line[i] = '\0';
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}