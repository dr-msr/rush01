/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:51:47 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 14:21:04 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"
#include <stdlib.h>

int	grid_initialisation(void)
{
	int	i;
	int	j;

	g_grid = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		g_grid[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
				g_grid[i][j] = 0;
				j++;
		}
		i++;
	}
	return (0);
}
