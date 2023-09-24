/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:14:43 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:14:44 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	check_row_right(int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (col != 3)
		return (1);
	i = 4;
	tallest = -1;
	count_view = 0;
	while (--i >= 0)
	{
		if (g_grid[row][i] > tallest)
		{
			tallest = g_grid[row][i];
			count_view++;
		}
	}
	if (clues[row] == count_view)
		return (1);
	return (0);
}
