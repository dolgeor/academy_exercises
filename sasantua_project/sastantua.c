/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:07:16 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/09 22:31:05 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_c0;
int g_i;
int g_j;
int g_ml;
int g_k;

int		ft_putchar(char c);

int		ft_width_of_level(int i)
{
	if (i == 0)
		return (7);
	return (ft_width_of_level(i - 1) + 2 * ((i + 1) / 2 + 1 + (3 + i)));
}

void	ft_pr(int l, int v, int s)
{
	g_j = -1;
	while (++g_j < l + g_ml)
	{
		if (g_ml == 0 && g_i > 2 - s % 2
				&& g_j >= l / 2 - (s - 1) / 2 && g_j <= l / 2 + (s - 1) / 2)
		{
			if (s >= 5 && g_i == 2 - s % 2 + (s - 1) / 2 + 1
					&& g_j == l / 2 + (s - 1) / 2 - 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else if (g_j >= g_ml + l / 2 - g_i - g_k / 2 - (v + 1) / 2 - g_c0
				&& g_j <= g_ml + l / 2 + g_i + g_k / 2 + (v + 1) / 2 + g_c0)
			ft_putchar('*');
		else if (g_j == g_ml + l / 2 - g_i - g_k / 2 - (v + 1) / 2 - g_c0 - 1)
			ft_putchar('/');
		else if (g_j == g_ml + l / 2 + g_i + g_k / 2 + (v + 1) / 2 + g_c0 + 1)
		{
			ft_putchar('\\');
			break ;
		}
		else
			ft_putchar(' ');
	}
}

void	ft_print_level(int h, int l, int v, int s)
{
	g_k = 0;
	g_i = -1;
	g_c0 = 1;
	if (v > 0)
		g_k = ft_width_of_level(v - 1);
	g_ml = (ft_width_of_level(s - 1) - l) / 2;
	if (g_k == 0)
		g_c0 = 0;
	while (++g_i < h)
	{
		ft_pr(l, v, s);
		ft_putchar('\n');
	}
}

void	sastantua(int size)
{
	int r;
	int height;
	int length;

	r = 0;
	while (r < size)
	{
		height = 3 + r;
		length = ft_width_of_level(r);
		ft_print_level(height, length, r, size);
		r++;
	}
}
