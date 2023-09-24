/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:11:25 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 15:11:26 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	conversion(char *a)
{
	return (*a - '0');
}

int	validateinput(char *argv[])
{
	int	count;
	int	k;
	int	j;

	clues_init();
	count = 1;
	k = 0;
	while (k < 4)
	{	
		j = 0;
		while (j < 4)
		{
			g_clues[k][j] = conversion(argv[count]);
			if (g_clues[k][j] < 1 || g_clues[k][j] > 4)
			{
				return (0);
			}
			count++;
			j++;
		}
		k++;
	}
	return (1);
}
