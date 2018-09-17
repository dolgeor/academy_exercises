/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:32:29 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/25 09:32:31 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int			ft_fl_size(char *av)
{
	t_struct	mp;
	int			i;
	int			fd;

	fd = open(av, O_RDONLY);
	i = 0;
	read(fd, &(mp.buff), 1);
	while (mp.buff != '\n')
	{
		read(fd, &(mp.buff), 1);
		i++;
	}
	close(fd);
	return (i);
}

t_struct	ft_fill_t_struct(char *av)
{
	t_struct	mp;
	int			i;
	int			fd;
	char		*first_l;

	i = ft_fl_size(av);
	first_l = (char*)malloc(sizeof(char) * i);
	fd = open(av, O_RDONLY);
	i = 0;
	read(fd, &(mp.buff), 1);
	while (mp.buff != '\n')
		A;
	mp.full = first_l[i - 1];
	mp.obstacle = first_l[i - 2];
	mp.empty = first_l[i - 3];
	first_l[i - 3] = 'c';
	mp.y = ft_atoi(first_l);
	i = 0;
	read(fd, &(mp.buff), 1);
	while (mp.buff != '\n')
		B;
	mp.x = i;
	close(fd);
	free(first_l);
	return (mp);
}

int			**ft_second_step(char *av, t_struct t_s)
{
	M;
	N;
	while (t_s.buff != '\n')
		read(fd, &(t_s.buff), 1);
	array = (int **)malloc(sizeof(int **) * (t_s.y));
	while (i < (t_s.y))
		array[i++] = (int *)malloc(sizeof(int *) * (t_s.x));
	i = 0;
	while (i < t_s.y)
	{
		j = 0;
		while (j < t_s.x)
		{
			read(fd, &t_s.buff, 1);
			if (t_s.buff == t_s.empty)
				array[i][j] = 1;
			else if (t_s.buff == t_s.obstacle)
				array[i][j] = 0;
			j++;
		}
		read(fd, &t_s.buff, 1);
		i++;
	}
	close(fd);
	return (array);
}
