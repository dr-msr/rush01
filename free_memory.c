/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:19:05 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:19:24 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"
#include <stdlib.h>

void	free_memory(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g_grid[i]);
		i++;
	}
	free(g_grid);
	i = 0;
	while (i < 4)
	{
		free(g_clues[i]);
		i++;
	}
	free(g_clues);
}
