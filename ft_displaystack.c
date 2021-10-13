/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaystack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:31:15 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/08 12:10:51 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
//#include <stdio.h>

//these 3 functions display the stacks with their current numbers
//and can be used for checking for errors:

//void	ft_displaystk(t_stack *actualstack)
//{
//	int	counter;

//	counter = 0;
//	while (counter < actualstack->stacksize_curt)
//	{
//		counter++;
//	}
//}

///*
//** Prints out the 'stack' array up to 'size'
//*/
//void	ft_printStack(t_stack *actualstack)
//{
//	int	stackindex;

//	stackindex = 0;
//	while (stackindex < actualstack->stacksize_curt)
//	{
//		printf("%d ", actualstack->actualstack[stackindex]);
//		stackindex++;
//	}
//	printf("\n");
//}

//void	ft_printAandB(t_p_s *mystruct)
//{
//	printf("---------------------------------------------\n");
//	ft_printStack(&mystruct->stacka);
//	ft_printStack(&mystruct->stackb);
//	printf("---------------------------------------------\n");
//}

//this function prints the operations history
void	ft_print_op(t_list *mylst)
{
	if (mylst == NULL)
		return ;
	ft_print_op(mylst->next);
	ft_printf("%s\n", mylst->content);
}
