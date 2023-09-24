#include "rush_01.h"

void	free_memory(void)
{
	int	i;
	
	i = 0;	
	
	while (i < SIZE) 	
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	i = 0;
	
    while (i < SIZE)
	{
		free(clues[i]);
		i++;
    }
	free(clues);
}
