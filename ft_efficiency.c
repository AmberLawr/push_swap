/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_efficiency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:00:10 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/28 19:20:34 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_addto_lst(t_list **lst, char *str)
{
	ft_lstadd_front(lst, ft_lstnew(ft_strdup(str)));
}

void	ft_resetrotatea(t_stack *stacka, t_rotationnbr *current)
{
	int counter;

	counter = 0;
	while (counter < current->ra_amount)
	{
		ft_revrotate(stacka);
		counter++;
	}
}

//void	ft_resetrotateb(t_stack *stackb, t_rotationnbr *current)
//{
//	int counter;

//	counter = 0;
//	while (counter < current->rb_amount)
//	{
//		ft_revrotate(stackb);
//		counter++;
//	}
//}

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
		printf("pushable before rotate = %d\n", pushable);
		while (pushable == false)
		{
			ft_rotate(stacka);
			current.ra_amount++;
			pushable = ft_simulatesort(stackb, stacka);
			printf("pushable after rotate = %d\n", pushable);
		}
		ft_resetrotatea(stacka, &current);
		current = ft_best_way(*stacka, *stackb, &current);
		minimum = ft_comparemin(&minimum, &current);
		ft_rotate(stackb);
		i++;
	}
	return (minimum);
	printf("this is the minimal sum: %d", minimum.sum);
}

void	ft_sortfreal(t_stack *stacka, t_stack *stackb, t_rotationnbr *minimum, t_list	*mylst)
{
	int		index;

	mylst = NULL;
	printf("hi Im in sortforreal\n");
	index = 0;
	while (index < minimum->ra_amount)
	{
		printf("ra_amount: %d\n", minimum->ra_amount);	//
		ft_rotate(stacka);
		ft_addto_lst(&mylst, "ra");
		index++;
	}
	index = 0;
	while (index < minimum->rb_amount)
	{
		printf("rb_amount: %d\n", minimum->rb_amount);	//
		ft_rotate(stackb);
		ft_addto_lst(&mylst, "rb");
		index++;
	}
	index = 0;
	while (index < minimum->rr_amount)
	{
		printf("rr_amount: %d\n", minimum->rr_amount);	//
		ft_rotate(stacka);
		ft_rotate(stackb);
		ft_addto_lst(&mylst, "rr");
		index++;
	}
	index = 0;
	while (index < minimum->rra_amount)
	{
		printf("rra_amount: %d\n", minimum->rra_amount);	//
		ft_revrotate(stacka);
		ft_addto_lst(&mylst, "rra");
		index++;
	}
	index = 0;
	while (index < minimum->rrb_amount)
	{
		printf("rrb_amount: %d\n", minimum->rrb_amount);	//
		ft_revrotate(stackb);
		ft_addto_lst(&mylst, "rrb");
		index++;
	}
	index = 0;
	while (index < minimum->rrr_amount)
	{
		printf("rrr_amount: %d\n", minimum->rrr_amount);	//
		ft_revrotate(stacka);
		ft_revrotate(stackb);
		ft_addto_lst(&mylst, "rrr");
		index++;
	}
	ft_push(stackb, stacka);
	ft_addto_lst(&mylst, "pa");
}
