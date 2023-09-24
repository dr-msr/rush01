/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:46:51 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 14:46:52 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_map(char *str, int length)
{
	int	row;
	int	col;
	int	index;

	row = 0;
	col = 0;
	index = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			if (index < length)
			{
				g_clues[row][col] = conversion(&str[index]);
				index++;
				index++;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

int	ft_verify(int length, char *argv)
{
	int	i;

	if (length != 31)
		return (1);
	i = 0;
	while (i <= length - 1)
	{
		if ((argv[i] >= '1' && argv[i] <= '4') || (argv[i] == 32))
		{
			i++;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_verify(ft_strlen(argv[1]), argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	clues_init();
	if (ft_map(argv[1], ft_strlen(argv[1])) == 1)
		return (1);
	grid_initialisation();
	if (ft_solve(0, 0))
		printgrid();
	else
	{	
		write(1, "Error\n", 6);
		return (1);
	}
	free_memory();
	return (0);
}
