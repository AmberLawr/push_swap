
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 12:47:57 by jzhou             #+#    #+#              #
#    Updated: 2021/06/22 12:47:57 by jzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

SRC = ft_push_swap.c ft_swap_fct.c ft_displaystack.c ft_errorhandle.c\
	ft_sort.c ft_efficiency.c ft_leastsum.c ft_best_way.c ft_minimumop.c\

LIBFT_PATH = ./libft/

MAKE = make

OBJ :=  $(SRC:.c=.o)

all: $(NAME)


$(NAME): sub_libft $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_PATH)libft.a -o $(NAME)

sub_libft:
	$(MAKE) all libft.a -C $(LIBFT_PATH)

clean:
	rm -f *.out
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all
