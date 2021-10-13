/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimumop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:38 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 20:07:16 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//the following 2 functions calculate the amount of rr and rrr operations.
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

//this function returns the minimum of the struct version
//by comparing the sum of steps needed to make stackb "pushable"
t_rotationnbr	ft_comparemin(t_rotationnbr *min, t_rotationnbr *cur)
{
	if (cur->sum < min->sum)
		min = cur;
	return (*min);
}
