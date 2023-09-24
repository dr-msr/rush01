/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:17:01 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 13:17:50 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"
#include <stdlib.h>

int	clues_init(void)
{
	int	i;

	i = 0;
	g_clues = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		g_clues[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	return (0);
}
