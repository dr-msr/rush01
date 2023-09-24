#include "rush_01.h"

int validateinput(char *argv[])
 {
	int count = 1;
    int i = 0;
	int k = 0;
	clues_init();
	
    while (k < SIZE) 
	{	
		int j = 0;
        while (j < SIZE) 
		{
            clues[k][j] = atoi(argv[count]); 
            if (clues[k][j] < 1 || clues[k][j] > SIZE) 
			{
                return 0;
            }
            count++;
            j++;
        }
        k++;
    }return 1; 
}
