#include "rush_01.h"

int	check_row_left(int **grid, int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1; 
	tallest = 0;
	count_view = 0; 
	while (++i <= col)
	{
		if (grid[row][i] > tallest)
		{
			tallest = grid[row][i]; 
			count_view++; 
		}
	}
	if ((col == 3 && clues[row] == count_view) 
		|| (col != 3 && clues[row] >= count_view)) 
		return (1);
	return (0);
}