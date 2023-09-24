#include "rush_01.h"

int	check_col_up(int **grid,int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1; 
	tallest = 0;
	count_view = 0;
	while (++i <= row)
	{
		if (grid[i][col] > tallest)
		{
			tallest = grid[i][col]; 
			count_view++; 
		}
	}
	if ((row == 3 && clues[col] == count_view) 
		|| (row != 3 && clues[col] >= count_view))
		return (1);
	return (0);
}