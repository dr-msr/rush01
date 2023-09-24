/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahim <mrahim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:54:38 by mrahim            #+#    #+#             */
/*   Updated: 2023/09/24 14:54:40 by mrahim           ###   ########.KL       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH_01_H

int			**g_grid;

int			**g_clues;

int			validateinput(char	*argv[]);

void		printgrid(void);

void		free_memory(void);

int			grid_initialisation(void);

int			clues_init(void);

int			check_col_up(int clues[4], int row, int col);

int			check_col_down(int clues[4], int row, int col);

int			check_row_left(int clues[4], int row, int col);

int			check_row_right(int clues[4], int row, int col);

int			ft_check(int row, int column);

int			ft_notduplicate(int row, int col, int num);

int			ft_solve_next(int row, int col);

int			ft_solve(int row, int col);

int			conversion(char *a);

#endif
