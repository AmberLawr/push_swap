/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leastsum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:22:56 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 20:05:43 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//these functions use a copy of the original struct in order for the
//actual struck to remain unchanged.
//here we calculate the steps needed for sorting stackb so
//it becomes "pushable".
int	ft_rarb(t_rotationnbr min)
{
	min.rr_amount = ft_minrr(min);
	min.ra_amount = min.ra_amount - min.rr_amount;
	min.rb_amount = min.rb_amount - min.rr_amount;
	min.rra_amount = 0;
	min.rrb_amount = 0;
	min.rrr_amount = 0;
	min.sum = min.ra_amount + min.rb_amount + min.rr_amount;
	return (min.sum);
}

int	ft_rrarb(t_rotationnbr min, t_stack stacka)
{
	min.rra_amount = stacka.stacksize_curt - min.ra_amount;
	min.rr_amount = 0;
	min.rrb_amount = 0;
	min.rrr_amount = 0;
	min.sum = min.rra_amount + min.rb_amount;
	return (min.sum);
}

int	ft_rarrb(t_rotationnbr min, t_stack stackb)
{
	min.rrb_amount = stackb.stacksize_curt - min.rb_amount;
	min.rr_amount = 0;
	min.rra_amount = 0;
	min.rrr_amount = 0;
	min.sum = min.ra_amount + min.rrb_amount;
	return (min.sum);
}

int	ft_rrarrb(t_rotationnbr min, t_stack stacka, t_stack stackb)
{
	min.rra_amount = stacka.stacksize_curt - min.ra_amount;
	min.rrb_amount = stackb.stacksize_curt - min.rb_amount;
	min.rrr_amount = ft_minrrr(min);
	min.rra_amount = min.rra_amount - min.rrr_amount;
	min.rrb_amount = min.rrb_amount - min.rrr_amount;
	min.ra_amount = 0;
	min.rb_amount = 0;
	min.rr_amount = 0;
	min.sum = min.rra_amount + min.rrb_amount + min.rrr_amount;
	return (min.sum);
}

//here we compare the sum of steps for each of the 4 possible cases
//and the struct version with the least amount of steps
//is being returned in the form of an index for further processing.
//ft_leastsum will be called in the function ft_best_way
//to reproduce the struct version with the least amount of steps
//for t_rotaionnbr current.
int	ft_leastsum(t_stack stacka, t_stack stackb, t_rotationnbr current)
{
	int	sumarray[4];
	int	minindex;
	int	counter;

	sumarray[0] = ft_rarb(current);
	sumarray[1] = ft_rrarb(current, stacka);
	sumarray[2] = ft_rarrb(current, stackb);
	sumarray[3] = ft_rrarrb(current, stacka, stackb);
	minindex = 0;
	counter = 0;
	while (counter < 4)
	{
		if (sumarray[counter] < sumarray[minindex])
			minindex = counter;
		counter++;
	}
	return (minindex);
}
