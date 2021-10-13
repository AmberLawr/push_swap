/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:41:04 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 20:21:02 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//the following 2 functions sort the stacks from the smallest number
//to the biggest number.
t_stack	ft_sorta(t_stack *stacka, t_list **mylst)
{
	int	index;

	index = ft_smallestnbr(stacka);
	while (index != 0)
	{
		ft_rotate(stacka);
		ft_addto_lst(mylst, "ra");
		index--;
	}
	return (*stacka);
}

t_stack	ft_sortb(t_stack *stackb, t_list **mylst)
{
	int	index;

	index = ft_smallestnbr(stackb);
	while (index != 0)
	{
		ft_rotate(stackb);
		ft_addto_lst(mylst, "rb");
		index--;
	}
	return (*stackb);
}

//this function is used to add the operation name
//to the operation history list
//and is called upon by different functions throughout the program.
void	ft_addto_lst(t_list **lst, char *str)
{
	ft_lstadd_front(lst, ft_lstnew(ft_strdup(str)));
}

//this function resets the rotation on stacka
//and puts it back to its original state of being.
void	ft_resetrotatea(t_stack *stacka, t_rotationnbr *current)
{
	int	counter;

	counter = 0;
	while (counter < current->ra_amount)
	{
		ft_revrotate(stacka);
		counter++;
	}
}
