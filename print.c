#include "rush_01.h"

void printGrid() 
{
	int i = 0;
    while (i < SIZE)
	{
		int j = 0;
         while (j < SIZE)
		{
            char digit = grid[i][j] + '0'; // Convert integer to character
			write(1, &digit , 1);
			write(1, " ", 1);
			j++;
        }
        write(1, "\n", 1);
		i++;
    } 
	write(1, "\n", 1);
}
/*
void printClues() /// just checking if it's printing the clues according our criteria
{   
    printf("Col Up: ");
    for (int i = 0; i < SIZE; i++) 
	{
        printf("%d ", clues[0][i]);
    }
    printf("\n");

    printf("Col Down: ");
    for (int i = 0; i < SIZE; i++) 
	{
        printf("%d ", clues[1][i]);
    }
    printf("\n");

    printf("Row Left: ");
    for (int i = 0; i < SIZE; i++)
		{
        printf("%d ", clues[2][i]);
		}
    printf("\n");

    printf("Row Right: ");
    for (int i = 0; i < SIZE; i++) 
	{
        printf("%d ", clues[3][i]);
    }
    printf("\n");
	write(1, "\n", 1);
}
*/