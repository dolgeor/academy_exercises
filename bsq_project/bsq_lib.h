/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:31:55 by ghdoloma          #+#    #+#             */
/*   Updated: 2017/07/26 16:01:31 by ghdoloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_LIB_H
# define BSQ_LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define Z t_end_of_square sq; t_struct mp; int max; int i; int **map;
# define R { free (first_l); return (0); }
# define L { close (fd); return (0); }
# define K mp.buff == '\n' || mp.buff == mp.empty || mp.buff == mp.obstacle
# define I y >= 1 && !(K)
# define A { first_l[i] = mp.buff; read(fd, &(mp.buff), 1); i++; }
# define B { read(fd, &(mp.buff), 1); i++; }
# define M 	int i; int j; int fd; int **array;
# define N i = 0; fd = open(av, O_RDONLY); read(fd, &(t_s.buff), 1);
# define C 	int fd; int x; int y; int i;
# define FD { if (!(first_l[fd] >= '0' && first_l[fd] <= '9')) R; fd--; }

typedef struct s_st	t_end_of_square;
typedef struct s_s	t_struct;

struct				s_st
{
	int ip;
	int jp;
};

struct				s_s
{
	char	empty;
	char	obstacle;
	char	full;
	char	buff;
	int		x;
	int		y;

};

t_end_of_square		ft_find_first_in(int **map, int y, int x, int max);
t_struct			ft_fill_t_struct(char *av);
void				ft_print_map(int **map, t_struct mp);
void				ft_final_init(t_end_of_square sq, int **map, int max);
void				ft_putchar(char c);
int					ft_fl_size(char *av);
int					ft_first_line(char *av);
int					ft_is_valid_y_x(char *av, t_struct mp);
int					**ft_second_step(char *av, t_struct t_s);
int					ft_atoi(char *str);
int					ft_find_min(int a, int b);
int					ft_find_sq(int **map, int y, int x);

#endif
