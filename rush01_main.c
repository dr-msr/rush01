#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char a)
{
    write(1,&a,1);
}

int	check_col_up(int grid[4][4],int input[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1; // start dari row paling atas
	tallest = 0;
	count_view = 0;
	while (++i <= row)
	{
		if (grid[i][col] > tallest)
		{
			tallest = grid[i][col]; // tiap kali jumpa building lagi tinggi, update "tallest"
			count_view++; // count berapa kali jumpa "lagi tinggi"
		}
	}
	if ((row == 3 && input[col] == count_view) // if counter equal to or less than input constraint, proceed
		|| (row != 3 && input[col] >= count_view))
		return (1);
	return (0);
}

int	check_col_down(int grid[4][4], int input[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (row != 3) // start check dari row paling bawah
		return (1);
	i = row + 1;
	tallest = 0;
	count_view = 0;
	while (--i >= 0) // dari bawah ke atas
	{
		if (grid[i][col] > tallest)
		{
			tallest = grid[i][col]; // tiap kali jumpa value lebih tinggi, update jadi "tallest"
			count_view++; // kira berapa banyak "lebih tinggi"
		}
	}
	if (input[col] == count_view) // kalau jumpa sama banyak baru return as success/proceed
		return (1);
	return (0);
}

int	check_row_left(int grid[4][4], int input[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1; // start paling kiri
	tallest = 0;
	count_view = 0; // counter untuk kira berapa kali "lagi tinggi"
	while (++i <= col)
	{
		if (grid[row][i] > tallest)
		{
			tallest = grid[row][i]; // tiap kali jumpa "lagi tinggi", update jadi tallest
			count_view++; // tambah counter
		}
	}
	if ((col == 3 && input[row] == count_view) // kalau sama counter dgn syarat, proceed 
		|| (col != 3 && input[row] >= count_view)) // kalau counter less than syarat, (proceed next value)
		return (1);
	return (0);
}

int	check_row_right(int grid[4][4], int input[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (col != 3) // start check dari column 3 (last column)
		return (1);
	i = 4;
	tallest = -1;
	count_view = 0; // counter untuk kira ada berapa kali "lagi tinggi"
	while (--i >= 0) // check dari kanan ke kiri (decreasing column)
	{
		if (grid[row][i] > tallest) // kalau jumpa value lebih tinggi, update that value jadi "tallest"
		{
			tallest = grid[row][i];
			count_view++; // setiap kali jumpa value (building) lebih tinggi, add satu counter
		}
	}
	if (input[row] == count_view) // kalau sama banyak counter dgn input requirement, baru pass
		return (1);
	return (0);
}

int	ft_check(int grid[4][4], int input[4][4], int row, int column)  // combine 4 criteria into binary output
{
	if (
      !check_col_up(grid, input[0], row, column) || 
		!check_col_down(grid, input[1], row, column) ||
		!check_row_left(grid, input[2], row, column) ||
		!check_row_right(grid, input[3], row, column)
	)
		return (0);
	return (1);
}

int ft_notDuplicate(int grid[4][4], int row, int col, int num) {  // checks duplicate
    int i = 0;
    while (i < 4) {
        if (grid[row][i] == num || grid[i][col] == num) { // runs through 1,2,3,4 if found anywhere within row/column
            return 0;
        }
        i++;
    }
    return 1;
}

int ft_solve(int grid[4][4], int input[4][4], int row, int col) {

    if (row == 4) { // runs from row 0 to 3 (4 rows), if value == 4 means all 0 to 3 already finished
        return 1;
    }

    if (grid[row][col] != 0) { // if current coordinate is already filled (not 0), move to next cell.
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 4) { // if current coordinate is end of row, proceed next row
            nextRow++;
            nextCol = 0;
        }
        return ft_solve(grid, input, nextRow, nextCol); // recursive
    }

    int value;
    for (value = 1; value <= 4; value++) {  // start filling the coordinate with value
        if (ft_notDuplicate(grid, row, col, value)) {  // check if duplicates (ft_notDuplicate)
            grid[row][col] = value; // if not duplicate, assign that value

            if (ft_check(grid, input, row, col)) // now, check for input constraint (building visibility)
            { 
                int nextRow = row, nextCol = col + 1; // if all input pass, move to next coordinate
                if (nextCol == 4) { // if filled the row, move to next row
                    nextRow++;
                    nextCol = 0;
                }
                if (ft_solve(grid, input, nextRow, nextCol)) { // exit function if reach here successfully 
                    return 1;
                }
            }

            grid[row][col] = 0; // if failed ft_check, resets back coordinate value to 0 and backtrack
        }
    }

    return 0; // if failed ft_notDuplicate (detect as duplicate), backtrack 
}


void ft_printgrid(int grid[4][4]) // prints the grid (solution)
{
   int i = 0;
    int j;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putchar(grid[i][j] + '0'); 
            ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

/*int main() { // start here

    int grid[4][4] = { {0} }; // initialize grid

    int input[4][4] = { // convert input to grid. this is template only

        {1, 2, 2, 2},
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {2, 2, 2, 1}

 //       {2, 3, 3, 1},
 //       {3, 1, 2, 3},
 //       {2, 1, 2, 2},
 //       {1, 4, 2, 3}
        
 //       {2, 2, 4, 1},
 //       {4, 2, 1, 4},
 //       {2, 2, 1, 3},
 //       {1, 2, 3, 2}

    };

    if (ft_solve(grid, input, 0, 0)) { // run ft_solve, returns 1 if solved
        ft_printgrid(grid); // if solved, print the finalized grid (solution)
    } else {
        write(1,"Error\n",6); // if returns 0 (no solution), prints error.
    }

    return 0;
}*/
int ft_atoi(char* str)
{
    // Initialize result
    int result = 0;
    int i;
    i = 0;
    
    while (str[i] != '\0')
    {
        result = result * 10 + str[i] - '0';
        // result with gets one digit placement holder at the end
        // then plus with value of str converted to int
        i++;
    }
    // return result.
    return (result);
}

int main(int argc, char **argv)
{  
    int i;
    int j;
    i = 0;
    j = 0;

    int grid[4][4] = {{0}}; // initialize grid

    int input[4][4];

    if (argc != 17)
    {
        write(1, "Must be only 16 int!", 20);
    }
    while (i < 4)
    {
        while (j < 4)
        {
            int index = i * 4 + j + 1; // calculates the place to take argument from
            input[i][j] = ft_atoi(argv[index]); // will take the argument according to number, top -> bottom -> left -> right
            j++;
        }
        i++;
    }
    
    if (ft_solve(grid, input, 0, 0)) // run ft_solve, returns 1 if solved
    { 
        ft_printgrid(grid); // if solved, print the finalized grid (solution)
    } 
    else 
    {
        write(1,"Error\n",6); // if returns 0 (no solution), prints error.
    }

    return (0);
}
