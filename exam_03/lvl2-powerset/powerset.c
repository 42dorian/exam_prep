#include <stdio.h>
#include <stdlib.h>

void	print_sol(int *set, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", set[i]);
		if (i + 1 < size)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	powerset(int index, int sum_wanted, int sum_curr, int *set, int size)
{
	if (index == size && sum_wanted == sum_curr)
		print_sol(set, size);
	if (index == size)
		return ;
	powerset(index + 1, sum_wanted, sum_curr + 1, set, size);
}

int	main(int ac, char **av)
{
	int	*set;
	int	i;
	int	sum;

	i = 2;
	sum = 0;
	if (ac <= 2)
		return (1);
	sum = atoi(av[1]);
	if (sum == 0)
		return (1);
	set = malloc(sizeof(int) * ac - 2);
	if (!set)
		return (1);
	while (i < ac)
	{
		set[i - 2] = atoi(av[i]);
		i++;
	}
	print_sol(set, ac - 2);
	powerset(0, atoi(av[1]), sum, set, ac - 2);
	free(set);
	return (0);
}
