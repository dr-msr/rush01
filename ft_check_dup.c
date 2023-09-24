#include "rush_01.h"

int	ft_check(int **grid, int **clues, int row, int column)  // combine 4 criteria into binary output
{
	if (
      !check_col_up(grid, clues[0], row, column) || 
		!check_col_down(grid, clues[1], row, column) ||
		!check_row_left(grid, clues[2], row, column) ||
		!check_row_right(grid, clues[3], row, column)
	)
		return (0);
	return (1);
}

int ft_notDuplicate(int **grid, int row, int col, int num) {  // checks duplicate
    int i = 0;
    while (i < 4) {
        if (grid[row][i] == num || grid[i][col] == num) { // runs through 1,2,3,4 if found anywhere within row/column
            return 0;
        }
        i++;
    }
    return 1;
}