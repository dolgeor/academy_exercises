# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghdoloma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 09:36:28 by ghdoloma          #+#    #+#              #
#    Updated: 2017/07/25 09:36:32 by ghdoloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	gcc -Wall -Wextra -Werror *.o -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
