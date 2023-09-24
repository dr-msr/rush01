#include "rush_01.h"

int ft_solve2(int **grid, int **clues, int row, int col)
{		  
			
			if (ft_check(grid, clues, row, col))
            { 
                int nextRow = row, nextCol = col + 1; 
                if (nextCol == 4) { 
                    nextRow++;
                    nextCol = 0;
                }
                if (ft_solve(grid, clues, nextRow, nextCol)) { 
                    return 1;
                }
            }

            grid[row][col] = 0; 
}
			