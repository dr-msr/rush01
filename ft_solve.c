/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:08:36 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 14:08:38 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	ft_try_values(int row, int col);

int	ft_solve(int row, int col)
{
	int	nextrow;
	int	nextcol;

	if (row == 4)
		return (1);
	if (g_grid[row][col] != 0)
	{
		nextrow = row;
		nextcol = col + 1;
		if (nextcol == 4)
		{
			nextrow++;
			nextcol = 0;
		}
		return (ft_solve(nextrow, nextcol));
	}
	return (ft_try_values(row, col));
}
