/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:13:35 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:13:44 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	check_row_left(int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1;
	tallest = 0;
	count_view = 0;
	while (++i <= col)
	{
		if (g_grid[row][i] > tallest)
		{
			tallest = g_grid[row][i];
			count_view++;
		}
	}
	if ((col == 3 && clues[row] == count_view)
		|| (col != 3 && clues[row] >= count_view))
		return (1);
	return (0);
}
