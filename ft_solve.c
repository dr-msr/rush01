#include "rush_01.h"

int ft_solve(int **grid, int **clues, int row, int col) {

    if (row == 4) { // runs from row 0 to 3 (4 rows), if value == 4 means all 0 to 3 already finished
        return 1;
    }

    if (grid[row][col] != 0) { // if current coordinate is already filled (not 0), move to next cell.
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 4) { // if current coordinate is end of row, proceed next row
            nextRow++;
            nextCol = 0;
        }
        return ft_solve(grid, clues, nextRow, nextCol); // recursive
    }

    int value;
    for (value = 1; value <= 4; value++) {  // start filling the coordinate with value
        if (ft_notDuplicate(grid, row, col, value)) {  // check if duplicates (ft_notDuplicate)
            grid[row][col] = value; // if not duplicate, assign that value

            if (ft_check(grid, clues, row, col)) // now, check for clues constraint (building visibility)
            { 
                int nextRow = row, nextCol = col + 1; // if all clues pass, move to next coordinate
                if (nextCol == 4) { // if filled the row, move to next row
                    nextRow++;
                    nextCol = 0;
                }
                if (ft_solve(grid, clues, nextRow, nextCol)) { // exit function if reach here successfully 
                    return 1;
                }
            }

            grid[row][col] = 0; // if failed ft_check, resets back coordinate value to 0 and backtrack
        }
    }

    return 0; // if failed ft_notDuplicate (detect as duplicate), backtrack 
}