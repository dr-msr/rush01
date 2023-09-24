#include "rush_01.h"

int clues_init()
{
	int i;
	i = 0;
	
	clues = (int **)malloc(SIZE * sizeof(int *));
    while (i < SIZE) 
	{
        clues[i] = (int *)malloc(SIZE * sizeof(int));
		i++;
    }
	return (0);
	
}