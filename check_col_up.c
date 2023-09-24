/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:11:35 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:11:37 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	check_col_up(int clues[4], int row, int col)
{
	int	i;
	int	count_view;
	int	tallest;

	i = -1;
	tallest = 0;
	count_view = 0;
	while (++i <= row)
	{
		if (g_grid[i][col] > tallest)
		{
			tallest = g_grid[i][col];
			count_view++;
		}
	}
	if ((row == 3 && clues[col] == count_view)
		|| (row != 3 && clues[col] >= count_view))
		return (1);
	return (0);
}
