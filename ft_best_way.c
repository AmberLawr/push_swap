/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:20:55 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/28 16:51:15 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_rotationnbr	*ft_rarb_init(t_rotationnbr *current)
{
	current->rr_amount = ft_minrr(*current);
	current->ra_amount = current->ra_amount - current->rr_amount;
	current->rb_amount = current->rb_amount - current->rr_amount;
	current->rra_amount = 0;
	current->rrb_amount = 0;
	current->rrr_amount = 0;
	current->sum = current->ra_amount + current->rb_amount + current->rr_amount;
	return (current);
}

t_rotationnbr	*ft_rrarb_init(t_rotationnbr *current, t_stack stacka)
{
	current->rr_amount = 0;
	current->rra_amount = stacka.stacksize_curt - current->ra_amount;
	current->ra_amount = 0;
	current->rrb_amount = 0;
	current->rrr_amount = 0;
	current->sum = current->rra_amount + current->rb_amount;
	return (current);
}

t_rotationnbr	*ft_rarrb_init(t_rotationnbr *current, t_stack stackb)
{
	current->rr_amount = 0;
	current->rrb_amount = stackb.stacksize_curt - current->rb_amount;
	current->rb_amount = 0;
	current->rra_amount = 0;
	current->rrr_amount = 0;
	current->sum = current->ra_amount + current->rrb_amount;
	return (current);
}

t_rotationnbr	*ft_rrarrb_init(t_rotationnbr *current, t_stack stacka, t_stack stackb)
{
	current->rra_amount = stacka.stacksize_curt - current->ra_amount;
	current->rrb_amount = stackb.stacksize_curt - current->rb_amount;
	current->rrr_amount = ft_minrrr(*current);
	current->rra_amount = current->rra_amount - current->rrr_amount;
	current->rrb_amount = current->rrb_amount - current->rrr_amount;
	current->ra_amount = 0;
	current->rb_amount = 0;
	current->rr_amount = 0;
	current->sum = current->rra_amount + current->rrb_amount + current->rrr_amount;
	return (current);
}

t_rotationnbr	ft_best_way(t_stack stacka, t_stack stackb, t_rotationnbr *current)
{
	int	minindex;

	minindex = ft_leastsum(stacka, stackb, *current);
	if (minindex == 0)
		current = ft_rarb_init(current);
	else if (minindex == 1)
		current = ft_rrarb_init(current, stacka);
	else if (minindex == 2)
		current = ft_rarrb_init(current, stackb);
	else if (minindex == 3)
		current = ft_rrarrb_init(current, stacka, stackb);
	return (*current);
}
