/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:09:49 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 14:10:52 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	ft_try_values(int row, int col)
{
	int	value;

	value = 1;
	while (value <= 4)
	{
		if (ft_notduplicate(row, col, value))
		{
			g_grid[row][col] = value;
			if (ft_check(row, col))
			{
				if (ft_solve_next(row, col))
					return (1);
			}
			g_grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}

int	ft_solve_next(int row, int col)
{
	int	nextrow;
	int	nextcol;

	nextrow = row;
	nextcol = col + 1;
	if (nextcol == 4)
	{
		nextrow++;
		nextcol = 0;
	}
	if (nextrow == 4)
	{
		return (1);
	}
	return (ft_try_values(nextrow, nextcol));
}
