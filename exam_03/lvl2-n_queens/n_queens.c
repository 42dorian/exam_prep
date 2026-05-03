#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *board, int col, int row)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (c < col)
	{
		r = board[c];
		if (r == row)
			return (0);
		if ((r - c) == (row - col))
			return (0);
		if ((r + c) == (row + col))
			return (0);
		c++;
	}
	return (1);
}

void	print_sol(int *board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i + 1 < size)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void	n_queens(int *board, int col, int size)
{
	int	row;

	row = 0;
	if (col == size)
	{
		print_sol(board, size);
		return ;
	}
	while (row < size)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			n_queens(board, col + 1, size);
		}
		row++;
	}
}

int	main(int ac, char const **av)
{
	int	size;
	int	*board;

	if (ac != 2)
		return (1);
	size = atoi(av[1]);
	if (size <= 0)
		return (0);
	board = malloc(sizeof(int) * size);
	if (!board)
		return (1);
	n_queens(board, 0, size);
	free(board);
	return (0);
}
