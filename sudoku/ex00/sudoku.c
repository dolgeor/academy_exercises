/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 15:37:39 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/16 20:48:22 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_ls(int *x, int *y, t_t *t, int *num)
{
	while (*num < 10)
	{
		if ((ft_same_square(*x, *y, *num) == 0) &&
				(ft_same_row(*y, *num) == 0) && (ft_same_column(*x, *num) == 0))
		{
			g_sudoku[*x][*y] = *num;
			if (*x == 8 && *y == 8)
				return (1);
			ft_step1(&(*x), &(*y), &(t->tx), &(t->ty));
			if (ft_solve_sudoku(t->tx, t->ty) == 1)
				return (1);
		}
		*num = *num + 1;
	}
	g_sudoku[*x][*y] = 0;
	return (0);
}

int		ft_solve_sudoku(int x, int y)
{
	int num;
	t_t t;

	num = 1;
	t.tx = 0;
	t.ty = 0;
	if (g_sudoku[x][y] != 0)
	{
		if (x == 8 && y == 8)
			return (1);
		ft_step(&x, &y);
		return ((ft_solve_sudoku(x, y) == 1) ? 1 : 0);
	}
	if (g_sudoku[x][y] == 0)
		return (ft_ls(&x, &y, &t, &num));
	return (0);
}

int		ft_strlen(int argc, char **argv)
{
	int i;
	int j;
	int len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0 && ((argv[i][j] >= '1' && argv[i][j] <= '9')
					|| argv[i][j] == '.'))
			j++;
		len = len + j;
		i++;
	}
	return (len);
}

int		main(int argc, char **argv)
{
	int x;
	int y;
	int i;
	int res;

	x = 0;
	y = 0;
	i = 1;
	if (argc != 10 || ft_strlen(argc, argv) != 81)
		write(1, "Erreur\n", 7);
	else
	{
		ft_init(&argv[1]);
		res = ft_solve_sudoku(x, y);
		if (res == 1)
			ft_print();
		else if (res == 0)
			write(1, "Erreur\n", 7);
	}
	return (0);
}
