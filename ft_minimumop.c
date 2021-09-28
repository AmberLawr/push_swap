/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimumop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:38 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/28 19:25:30 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_minrr(t_rotationnbr minimum)
{
	int	index;

	index = 0;
	while (index < minimum.ra_amount && index < minimum.rb_amount)
	{
		minimum.rr_amount++;
		index++;
	}
	return (minimum.rr_amount);
}

int	ft_minrrr(t_rotationnbr minimum)
{
	int	index;

	index = 0;
	while (index < minimum.rra_amount && index < minimum.rrb_amount)
	{
		minimum.rrr_amount++;
		index++;
	}
	return (minimum.rrr_amount);
}

t_rotationnbr	ft_comparemin(t_rotationnbr *min, t_rotationnbr *cur)
{
	printf("current sum: %d\n", cur->sum);
	printf("minimal sum: %d\n", min->sum);
	if (cur->sum < min->sum)
		min = cur;
	return (*min);
}

t_stack ft_sorta(t_stack *stacka, t_list *mylst)
{
	int index;

	index = ft_smallestnbr(stacka);

	while (index != 0)
	{
		ft_rotate(stacka);
		ft_addto_lst(&mylst, "ra");
		index--;
	}
	return (*stacka);
}
