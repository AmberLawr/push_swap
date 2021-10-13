/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:14:30 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/02 19:15:08 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//this function is used to free strings
void	ft_destructstr(char **strinput)
{
	int	index;

	index = 0;
	while (strinput[index] != NULL)
	{
		free(strinput[index]);
		index++;
	}
	free(strinput);
}

//this function splits and counts how many numbers
//are given to the terminal and checks for errors in the input.
void	ft_readargs(int argc, char **argv, t_p_s *mystruct)
{
	char	**strinput;
	int		argcindex;
	int		splitindex;

	argcindex = 1;
	while (argcindex < argc)
	{
		strinput = ft_split(argv[argcindex], ' ');
		splitindex = 0;
		while (strinput[splitindex] != NULL)
		{
			if (ft_checkdigit(strinput[splitindex]) == -1
				|| ft_maxvalue(strinput[splitindex]) == -1)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			mystruct->stacka.stacksize_fst++;
			splitindex++;
		}
		ft_destructstr(strinput);
		argcindex++;
	}
}

//this function initializes the structs "stacka" and "stackb" with zeros.
void	ft_init_stack(t_p_s *mystruct)
{
	mystruct->stacka.actualstack
		= ft_calloc(mystruct->stacka.stacksize_fst, sizeof(int));
	mystruct->stackb.actualstack
		= ft_calloc(mystruct->stacka.stacksize_fst, sizeof(int));
}

//this function reads in the numbers given to the terminal
//and stores them in the array "stacka".
//it also checks for the error whether there are doubles in the numbers.
void	ft_fillstacka(int argc, char **argv, t_p_s *mystruct)
{
	char	**strinput;
	int		argcindex;
	int		splitindex;

	argcindex = 1;
	mystruct->stacka.stacksize_curt = 0;
	while (argcindex < argc)
	{
		strinput = ft_split(argv[argcindex], ' ');
		splitindex = 0;
		while (strinput[splitindex] != NULL)
		{
			mystruct->stacka.actualstack[mystruct->stacka.stacksize_curt]
				= ft_atoi(strinput[splitindex]);
			splitindex++;
			mystruct->stacka.stacksize_curt++;
		}
		ft_destructstr(strinput);
		argcindex++;
	}
	if (ft_checkdouble(&mystruct->stacka) == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_p_s			mystruct;
	t_rotationnbr	minimum;
	t_list			*mylst;

	mylst = NULL;
	ft_bzero(&mystruct, sizeof(mystruct));
	ft_readargs(argc, argv, &mystruct);
	ft_init_stack(&mystruct);
	ft_fillstacka(argc, argv, &mystruct);
	ft_sort8size(&mystruct, &minimum, &mylst);
	ft_print_op(mylst);
	return (0);
}
