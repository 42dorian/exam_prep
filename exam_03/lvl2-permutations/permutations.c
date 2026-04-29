#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	sort_arr(char *s, int size)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < size - 1)
	{
		if (s[i] > s[i + 1])
		{
			c = s[i];
			s[i] = s[i + 1];
			s[i + 1] = c;
			i = 0;
		}
		else
			i++;
	}
}

void	permute(char *str, char *result, int slot, int size)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (slot == size)
	{
		puts(result);
		return ;
	}
	while (i < size)
	{
		if (str[i])
		{
			c = str[i];
			str[i] = 0;
			result[slot] = c;
			permute(str, result, slot + 1, size);
			str[i] = c;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char *result;
	int size;
	if (ac != 2)
		return (1);
	size = ft_strlen(av[1]);
	result = calloc(sizeof(char), size + 1);
	sort_arr(av[1], size);
	permute(av[1], result, 0, size);
	return (0);
}