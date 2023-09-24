#include "rush_01.h"

int	check_row_right(int **grid, int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (col != 3) 
		return (1);
	i = 4;
	tallest = -1;
	count_view = 0; 
	while (--i >= 0) 
	{
		if (grid[row][i] > tallest) 
		{
			tallest = grid[row][i];
			count_view++; 
		}
	}
	if (clues[row] == count_view) 
		return (1);
	return (0);
}