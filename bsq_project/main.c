/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:32:05 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/26 11:56:15 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_exist_f(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

void	ft_solve_fmap(char *av)
{
	Z;
	if (ft_exist_f(av))
		write(2, "map error\n", 10);
	else
	{
		mp = ft_fill_t_struct(av);
		if (!(ft_first_line(av) && ft_is_valid_y_x(av, mp)))
			write(2, "map error\n", 10);
		else
		{
			map = ft_second_step(av, mp);
			max = ft_find_sq(map, mp.y, mp.x);
			sq = ft_find_first_in(map, mp.y, mp.x, max);
			ft_final_init(sq, map, max);
			ft_print_map(map, mp);
			i = 0;
			while (i < mp.y)
			{
				free(map[i]);
				i++;
			}
			free(map);
		}
	}
}

int		main(int ac, char **av)
{
	char	buf;
	int		fd;
	int		j;

	j = 1;
	while (j < ac)
	{
		ft_solve_fmap(av[j]);
		if (j < ac - 1)
			ft_putchar('\n');
		j++;
	}
	if (ac == 1)
	{
		fd = open("bukluc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
				| S_IWUSR | S_IRGRP | S_IROTH);
		while (read(0, &buf, 1))
			write(fd, &buf, 1);
		close(fd);
		ft_solve_fmap("bukluc");
	}
	return (0);
}
