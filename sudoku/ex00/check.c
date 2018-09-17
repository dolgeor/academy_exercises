/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:42:59 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/16 17:29:53 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int g_sudoku[9][9] = {{0}};

int		ft_same_column(int x, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (g_sudoku[x][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int		ft_same_row(int y, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (g_sudoku[i][y] == num)
			return (1);
		i++;
	}
	return (0);
}

int		ft_change_x(int y)
{
	if (y < 3)
		y = 0;
	else if (y < 6)
		y = 3;
	else
		y = 6;
	return (y);
}

int		ft_same_square(int x, int y, int num)
{
	int i;
	int j;

	x = ft_change_x(x);
	y = ft_change_x(y);
	i = x;
	while (i < x + 3)
	{
		j = y;
		while (j < y + 3)
		{
			if (g_sudoku[i][j] == num)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
