#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	search_and_mask(char *s1, char *s2)
{
	int	i;
	int	j;
	int	s2_size;

	i = 0;
	j = 0;
	s2_size = ft_strlen(s2);
	while (s1[i])
	{
		if (ft_strncmp(&s1[i], s2, s2_size) == 0)
		{
			while (j < s2_size)
			{
				s1[i + j] = '*';
				j++;
			}
			j = 0;
			i += s2_size;
		}
		else
			i++;
	}
}

int	main(int argc, char *argv[])
{
	char	str[1024];
	int		read_bytes;

	if (argc != 2)
		return (1);
	while ((read_bytes = read(0, str, 1024)) > 0)
	{
		str[read_bytes] = '\0';
		search_and_mask(str, argv[1]);
		write(1, str, read_bytes);
	}
	return (0);
}
