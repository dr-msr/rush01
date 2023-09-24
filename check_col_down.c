#include "rush_01.h"

int	check_col_down(int **grid, int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (row != 3) 
		return (1);
	i = row + 1;
	tallest = 0;
	count_view = 0;
	while (--i >= 0) 
	{
		if (grid[i][col] > tallest)
		{
			tallest = grid[i][col]; 
			count_view++; 
		}
	}
	if (clues[col] == count_view) 
		return (1);
	return (0);
}