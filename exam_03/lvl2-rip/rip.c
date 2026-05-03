#include <stdio.h>

int	is_valid(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		if (count < 0)
			return (0);
		i++;
	}
	return (count == 0);
}

int	count_removal(char *str)
{
	int	i;
	int	r;
	int	l;

	i = 0;
	l = 0;
	r = 0;
	while (str[i])
	{
		if (str[i] == '(')
			l++;
		if (str[i] == ')')
		{
			if (l > 0)
				l--;
			else
				r++;
		}
		i++;
	}
	return (r + l);
}

void	rip(int i, char *str, int max_remove, int removed)
{
	char	c;

	c = 0;
	if (removed >= max_remove)
	{
		if (is_valid(str))
			puts(str);
		return ;
	}
	if (!str[i])
		return ;
	rip(i + 1, str, max_remove, removed);
	if (str[i] == '(' || str[i] == ')')
	{
		c = str[i];
		str[i] = ' ';
		rip(i + 1, str, max_remove, removed + 1);
		str[i] = c;
	}
}

int	main(int ac, char *av[])
{
	int	max_remove;

	if (ac != 2)
		return (1);
	max_remove = (int)count_removal(av[1]);
	rip(0, av[1], max_remove, 0);
	return (0);
}
