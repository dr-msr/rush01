

#ifndef RUSH_01_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#	define SIZE 4

int 	**grid;

int 	**clues;

int 	validateinput(char *argv[]);

void 	printGrid(void) ;

void 	printClues(void);

void	free_memory(void);

int 	grid_initialisation();

int 	clues_init();

int		check_col_up(int **grid,int clues[4], int row, int col);

int		check_col_down(int **grid, int clues[4], int row, int col);

int		check_row_left(int **grid, int clues[4], int row, int col);

int		check_row_right(int **grid, int clues[4], int row, int col);

int		ft_check(int **grid, int **clues, int row, int column);

int 	ft_notDuplicate(int **grid, int row, int col, int num);

int 	ft_solve(int **grid, int **clues, int row, int col);





#endif
