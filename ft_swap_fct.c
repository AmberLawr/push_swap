/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:57:42 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 19:55:57 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//here you can find all the operational functions of push_swap
void	ft_rotate(t_stack *actualstack)
{
	int	temp;
	int	counter;

	counter = 0;
	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[0];
	while (counter < actualstack->stacksize_curt - 1)
	{
		actualstack->actualstack[counter]
			= actualstack->actualstack[counter + 1];
		counter++;
	}
	actualstack->actualstack[counter] = temp;
}

void	ft_revrotate(t_stack *actualstack)
{
	int	temp;
	int	counter;

	counter = actualstack->stacksize_curt - 1;
	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[counter];
	while (counter > 0)
	{
		actualstack->actualstack[counter]
			= actualstack->actualstack[counter - 1];
		counter--;
	}
	actualstack->actualstack[0] = temp;
}

void	ft_swap(t_stack *actualstack)
{
	int	temp;

	if (actualstack->stacksize_curt < 2)
		return ;
	temp = actualstack->actualstack[0];
	actualstack->actualstack[0] = actualstack->actualstack[1];
	actualstack->actualstack[1] = temp;
}

void	ft_push(t_stack *from, t_stack *to)
{
	int	index;

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
