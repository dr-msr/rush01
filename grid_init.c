#include "rush_01.h"

int grid_initialisation()
{
	int i;
	
grid = (int **)malloc(SIZE * sizeof(int *));
	i = 0;
	while (i < SIZE) 
	{
        grid[i] = (int *)malloc(SIZE * sizeof(int));
		i++;
    }
   i = 0;
  while (i < SIZE) 
		{
			int j = 0;
			while (j < SIZE)
			{
				grid[i][j] = 0;
				j++;
			}
		i++;
		}
}