/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:03:11 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/02 12:59:21 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//we use this function to push all of stacka into stackb
void	ft_push_all(t_stack *from, t_stack *to, t_list **mylst)
{
	while (from->stacksize_curt > 0)
	{
		ft_push(from, to);
		ft_addto_lst(mylst, "pb");
	}
}

//this is an outsourced function used to find
//the smallest number inside a given stack filled with numbers
//it returns the index of the smallest value.
int	ft_smallestnbr(t_stack *actualstack)
{
	int	minimum;
	int	tmpsize;

	minimum = actualstack->actualstack[0];
	tmpsize = 1;
	while (tmpsize < actualstack->stacksize_curt)
	{
		if (actualstack->actualstack[tmpsize] < minimum)
			minimum = actualstack->actualstack[tmpsize];
		tmpsize++;
	}
	tmpsize = 0;
	while (actualstack->actualstack[tmpsize] != minimum)
		tmpsize++;
	return (tmpsize);
}

//this function is only used in ft_sortfive
//for hardcoding certain edge cases
bool	ft_worstpos(t_stack *actualstack)
{
	int	index;

	index = 0;
	if (actualstack->actualstack[0] < actualstack->actualstack[1]
		&& actualstack->actualstack[0] < actualstack->actualstack[2]
		&& actualstack->actualstack[0] < actualstack->actualstack[3]
		&& actualstack->actualstack[0] > actualstack->actualstack[4])
		return (true);
	else
		return (false);
}

/*
** Returns true if 'stack' is sorted.
** Sorted in this case can be "2 3 4 5 1" as well.
*/
bool	ft_issorted(t_stack *stack)
{
	int			tmpsize;
	int			nOfCmps;

	tmpsize = ft_smallestnbr(stack);
	nOfCmps = 0;
	while (nOfCmps < stack->stacksize_curt - 1)
	{
		if (tmpsize == stack->stacksize_curt - 1)
		{
			if (stack->actualstack[tmpsize] > stack->actualstack[0])
				return (false);
			tmpsize = -1;
		}
		else if (stack->actualstack[tmpsize] > stack->actualstack[tmpsize + 1])
			return (false);
		tmpsize++;
		nOfCmps++;
	}
	return (true);
}

/*
** Simulates push(from, to) and returns true if 'to' stack would remain sorted.
** Does not change either stack.
*/
bool	ft_simulatesort(t_stack *from, t_stack *to)
{
	bool	pushable;

	pushable = false;
	if (from->stacksize_curt > 0)
	{
		if (ft_issorted(to) == true)
		{
			ft_push(from, to);
			pushable = ft_issorted(to);
			ft_push(to, from);
			return (pushable);
		}
		return (pushable);
	}
	else
	{
		pushable = ft_issorted(to);
		return (pushable);
	}
}
