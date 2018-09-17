/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:36:09 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/25 09:36:16 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_atoi(char *str)
{
	int			res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\n'
			|| *(str + i) == '\r' || *(str + i) == '\v' || *(str + i) == '\f')
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10;
		res = (res + (*(str + i) - '0') * sign);
		i++;
	}
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_map(int **map, t_struct mp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mp.y)
	{
		j = 0;
		while (j < mp.x)
		{
			if (map[i][j] == 0)
				ft_putchar(mp.obstacle);
			else if (map[i][j] == -1)
				ft_putchar(mp.full);
			else
				ft_putchar(mp.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
