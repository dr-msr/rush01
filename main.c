#include "rush_01.h"

int	main(int argc, char *argv[]) 
{
	int i;
	
    if (argc != SIZE * 4 + 1 || !validateinput(argv)) // argument checking
	{	
		write(1, "Error",5);
        return (1);
    }
	grid_initialisation();
	if (ft_solve(grid, clues, 0, 0)) 
	{
        printGrid();
    } 
	else 
	{
        write(1, "Error\n",5);
    }
	i = 0;
	free_memory();
    return 0;
}
