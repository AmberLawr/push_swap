/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_efficiency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:00:10 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 19:49:00 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//this funciton handles what to do while stackb is not pushable to stacka
bool	ft_npushable(t_stack *stacka, t_stack *stackb, t_rotationnbr *current)
{
	bool	pushable;

	ft_rotate(stacka);
	current->ra_amount++;
	pushable = ft_simulatesort(stackb, stacka);
	return (pushable);
}

//this funtion returns the path with the minimum amount of steps needed to sort
t_rotationnbr	ft_opcount(t_stack *stacka, t_stack *stackb)
{
	t_rotationnbr	current;
	t_rotationnbr	minimum;
	bool			pushable;
	int				i;

	ft_bzero(&minimum, sizeof(minimum));
	i = 0;
	minimum.sum = INFINITY;
	while (i < stackb->stacksize_curt)
	{
		ft_bzero(&current, sizeof(current));
		current.rb_amount = i;
		pushable = ft_simulatesort(stackb, stacka);
		while (pushable == false)
			pushable = ft_npushable(stacka, stackb, &current);
		ft_resetrotatea(stacka, &current);
		current = ft_best_way(*stacka, *stackb, &current);
		minimum = ft_comparemin(&minimum, &current);
		ft_rotate(stackb);
		i++;
	}
	return (minimum);
}

// These 2 functions are part of the sort_for_real function
void	ft_rotatesort(t_stack *stacka, t_stack *stackb,
	t_rotationnbr *minimum, t_list	**mylst)
{
	int	index;

	index = 0;
	while (index < minimum->ra_amount)
	{
		ft_rotate(stacka);
		ft_addto_lst(mylst, "ra");
		index++;
	}
	index = 0;
	while (index < minimum->rb_amount)
	{
		ft_rotate(stackb);
		ft_addto_lst(mylst, "rb");
		index++;
	}
	index = 0;
	while (index < minimum->rr_amount)
	{
		ft_rotate(stacka);
		ft_rotate(stackb);
		ft_addto_lst(mylst, "rr");
		index++;
	}
}

void	ft_revrotatesort(t_stack *stacka, t_stack *stackb,
	t_rotationnbr *minimum, t_list	**mylst)
{
	int	index;

	index = 0;
	while (index < minimum->rra_amount)
	{
		ft_revrotate(stacka);
		ft_addto_lst(mylst, "rra");
		index++;
	}
	index = 0;
	while (index < minimum->rrb_amount)
	{
		ft_revrotate(stackb);
		ft_addto_lst(mylst, "rrb");
		index++;
	}
	index = 0;
	while (index < minimum->rrr_amount)
	{
		ft_revrotate(stacka);
		ft_revrotate(stackb);
		ft_addto_lst(mylst, "rrr");
		index++;
	}
}

//this function sorts the path with the minimum steps
void	ft_sortfreal(t_stack *stacka, t_stack *stackb,
	t_rotationnbr *minimum, t_list	**mylst)
{
	ft_rotatesort(stacka, stackb, minimum, mylst);
	ft_revrotatesort(stacka, stackb, minimum, mylst);
	ft_push(stackb, stacka);
	ft_addto_lst(mylst, "pa");
}
