/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:37:30 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/16 21:12:46 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_step(int *x, int *y)
{
	if (*x < 8)
		*x = *x + 1;
	else
	{
		if (*y < 8)
		{
			*x = 0;
			*y = *y + 1;
		}
	}
}

void	ft_step1(int *x, int *y, int *tx, int *ty)
{
	if (*x < 8)
		*tx = *x + 1;
	else
	{
		if (*y < 8)
		{
			*tx = 0;
			*ty = *y + 1;
		}
	}
}

void	ft_init(char **c)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (c[i][j] == '.')
				g_sudoku[i][j] = 0;
			else if (c[i][j] >= '1' && c[i][j] <= '9')
				g_sudoku[i][j] = c[i][j] - '0';
			j++;
		}
		i++;
	}
}

void	ft_print(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = g_sudoku[i][j] + '0';
			write(1, &c, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
