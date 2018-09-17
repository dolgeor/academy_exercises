/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:02:00 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/26 12:34:04 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_are_same(char a, char b, char c)
{
	if (a == b)
		return (1);
	if (a == c)
		return (1);
	if (c == b)
		return (1);
	return (0);
}

int		ft_first_line(char *av)
{
	t_struct	mp;
	int			i;
	int			fd;
	char		*first_l;

	first_l = (char*)malloc(sizeof(char) * ft_fl_size(av));
	fd = open(av, O_RDONLY);
	i = 0;
	read(fd, &(mp.buff), 1);
	while (mp.buff != '\n')
	{
		first_l[i] = mp.buff;
		read(fd, &(mp.buff), 1);
		i++;
	}
	close(fd);
	fd = i - 1;
	if (fd < 3 || ft_are_same(first_l[fd], first_l[fd - 1], first_l[fd - 2]))
		R;
	fd = fd - 3;
	first_l[fd + 1] = 'a';
	while (fd >= 0)
		FD;
	free(first_l);
	return (1);
}

int		ft_is_valid_y_x(char *av, t_struct mp)
{
	C;
	i = 0;
	x = 0;
	y = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &(mp.buff), 1))
	{
		if (mp.buff == '\n')
		{
			y++;
			if (y > 1 && i - x - 1 != mp.x)
				L;
			x = i;
		}
		if (I)
			L;
		i++;
	}
	if (y - 1 != mp.y || mp.y < 1 || mp.x < 1 || mp.buff != 10)
		L;
	close(fd);
	return (1);
}
