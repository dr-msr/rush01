/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:22:05 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:27:55 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	ft_check(int row, int column)
{
	if (!check_col_up(g_clues[0], row, column)
		|| !check_col_down(g_clues[1], row, column)
		|| !check_row_left(g_clues[2], row, column)
		|| !check_row_right(g_clues[3], row, column)
	)
		return (0);
	return (1);
}

int	ft_notduplicate(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_grid[row][i] == num || g_grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
