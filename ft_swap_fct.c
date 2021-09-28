/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:57:42 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/26 12:21:37 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_stack *actualstack)
{
	int temp;
	int counter;

	counter = 0;
	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[0];
	while (counter < actualstack->stacksize_curt - 1)
	{
		actualstack->actualstack[counter] = actualstack->actualstack[counter + 1];
		counter++;
	}
	actualstack->actualstack[counter] = temp;	// -1
}

void	ft_revrotate(t_stack *actualstack)
{
	int temp;
	int counter;

	counter = actualstack->stacksize_curt - 1;
	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[counter];
	while (counter > 0)
	{
		actualstack->actualstack[counter] = actualstack->actualstack[counter - 1];
		counter--;
	}
	actualstack->actualstack[0] = temp;
}

void	ft_swap(t_stack *actualstack)
{
	int temp;

	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[0];
	actualstack->actualstack[0] = actualstack->actualstack[1];
	actualstack->actualstack[1] = temp;
}

void	ft_push(t_stack *from, t_stack *to)
{
	int index;

	if (from->stacksize_curt == 0)
		return ;
	index = to->stacksize_curt;
	while (index > 0)
	{
		to->actualstack[index] = to->actualstack[index - 1];
		index--;
	}
	to->actualstack[0] = from->actualstack[0];

	index = 0;
	while (index < from->stacksize_curt - 1)
	{
		from->actualstack[index] = from->actualstack[index + 1];
		index++;
	}
	to->stacksize_curt++;
	from->stacksize_curt--;
}

int	ft_sortstack(t_stack *actualstack)
{
	int	minindex;
	int	ra_amount;

	ra_amount = 0;
	minindex = ft_smallestnbr(actualstack);
	while (minindex != 0)
	{
		ft_rotate(actualstack);
		minindex--;
		ra_amount++;
	}
	return (ra_amount);
}
