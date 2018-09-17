/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:00:05 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/16 21:19:08 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>

int				g_sudoku[9][9];
typedef	struct	s_p
{
	int			tx;
	int			ty;
}				t_t;
int				ft_solve_sudoku(int x, int y);
void			ft_init(char **c);
void			ft_print(void);
void			ft_step(int *x, int *y);
void			ft_step1(int *x, int *y, int *tx, int *ty);
int				ft_same_column(int x, int num);
int				ft_same_row(int y, int num);
int				ft_same_square(int x, int y, int num);

#endif
