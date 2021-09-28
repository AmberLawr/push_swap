/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:14:30 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/28 19:28:04 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"
#include <stdio.h>

void	ft_destructstr(char **strinput)
{
	int index;

	index = 0;
	while (strinput[index] != NULL)
	{
		free(strinput[index]);
		index++;
	}
	free(strinput);
}

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
			mystruct->stacka.actualstack[mystruct->stacka.stacksize_curt] = ft_atoi(strinput[splitindex]);
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

void	ft_init_stack(t_p_s *mystruct)
{
	mystruct->stacka.actualstack = ft_calloc(mystruct->stacka.stacksize_fst, sizeof(int));
	mystruct->stackb.actualstack = ft_calloc(mystruct->stacka.stacksize_fst, sizeof(int));

}

int	main(int argc, char **argv)
{
	t_p_s			mystruct;
	t_rotationnbr	minimum;
	t_list			mylst;

	ft_bzero(&mystruct, sizeof(mystruct));
	ft_readargs(argc, argv, &mystruct);
	ft_init_stack(&mystruct);
	ft_fillstacka(argc, argv, &mystruct);
	ft_printAandB(&mystruct);

	//if (ft_issorted(&mystruct.stacka))
	//	printf("A is sorted\n");
	//else
	//	printf("A is not sorted\n");

	//ft_printAandB(&mystruct);
	//ft_swap(&mystruct.stacka);
	//ft_printAandB(&mystruct);
	//ft_rotate(&mystruct.stacka);
	//ft_printAandB(&mystruct);
	//ft_revrotate(&mystruct.stacka);
	//ft_printAandB(&mystruct);
	//ft_push(&mystruct.stacka, &mystruct.stackb);
	//ft_printAandB(&mystruct);
	//ft_push(&mystruct.stacka, &mystruct.stackb);
	//ft_printAandB(&mystruct);

	ft_push_all(&mystruct.stacka, &mystruct.stackb);
	ft_printAandB(&mystruct);

	while (mystruct.stackb.stacksize_curt > 0)
	{
		minimum = ft_opcount(&mystruct.stacka, &mystruct.stackb);
		ft_sortfreal(&mystruct.stacka, &mystruct.stackb, &minimum, &mylst);
		ft_printAandB(&mystruct);
	}
	mystruct.stacka = ft_sorta(&mystruct.stacka, &mylst);
	ft_printStack(&mystruct.stacka);
	return (0);
}
