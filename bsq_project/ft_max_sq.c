/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:33:01 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/25 09:33:03 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int					ft_find_sq(int **map, int y, int x)
{
	int max;
	int i;
	int j;

	i = 0;
	j = 0;
	max = map[0][0];
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] != 0 && j != 0 && i != 0)
				map[i][j] = ft_find_min(ft_find_min(map[i - 1][j],
					map[i][j - 1]), map[i - 1][j - 1]) + 1;
			if (map[i][j] > max)
				max = map[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

t_end_of_square		ft_find_first_in(int **map, int y, int x, int max)
{
	t_end_of_square sq;

	sq.ip = 0;
	sq.jp = 0;
	while (sq.ip < y)
	{
		sq.jp = 0;
		while (sq.jp < x)
		{
			if (map[sq.ip][sq.jp] == max)
				break ;
			sq.jp++;
		}
		if (map[sq.ip][sq.jp] == max)
			break ;
		sq.ip++;
	}
	return (sq);
}

void				ft_final_init(t_end_of_square sq, int **map, int max)
{
	int i;
	int j;

	i = sq.ip - max + 1;
	j = sq.jp - max + 1;
	while (i <= sq.ip)
	{
		j = sq.jp - max + 1;
		while (j <= sq.jp)
		{
			map[i][j] = -1;
			j++;
		}
		i++;
	}
}
