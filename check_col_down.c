/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:10:07 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:10:26 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	check_col_down(int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	if (row != 3)
		return (1);
	i = row + 1;
	tallest = 0;
	count_view = 0;
	while (--i >= 0)
	{
		if (g_grid[i][col] > tallest)
		{
			tallest = g_grid[i][col];
			count_view++;
		}
	}
	if (clues[col] == count_view)
		return (1);
	return (0);
}
