/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort8size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:25:22 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/07 19:50:53 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//this function sorts the stacks for 3 numbers
void	ft_sortthree(t_p_s *mystruct, t_list **mylst)
{
	int		index;
	bool	sorted;

	index = 0;
	sorted = ft_issorted(&mystruct->stacka);
	while (index < mystruct->stacka.stacksize_curt)
	{
		if (sorted == 1)
			mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
		else
		{
			ft_swap(&mystruct->stacka);
			ft_addto_lst(mylst, "sa");
			mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
		}
		sorted = ft_issorted(&mystruct->stacka);
		index++;
	}
}

//this function hardcodes certain edge cases that take too many steps to sort
//for the sortfive function
void	ft_sortworst(t_p_s *mystruct, t_rotationnbr *minimum, t_list **mylst)
{
	int	rotindex;

	rotindex = 0;
	ft_rotate(&mystruct->stacka);
	ft_addto_lst(mylst, "ra");
	while (rotindex < 3)
	{
		ft_push(&mystruct->stacka, &mystruct->stackb);
		ft_addto_lst(mylst, "pb");
		rotindex++;
	}
	while (mystruct->stackb.stacksize_curt > 0)
	{
		*minimum = ft_opcount(&mystruct->stacka, &mystruct->stackb);
		ft_sortfreal(&mystruct->stacka, &mystruct->stackb, minimum, mylst);
	}
	mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
}

//this is the normal sort without the worst case
//for the sortfive function
void	ft_sortnormal(t_p_s *mystruct, t_rotationnbr *minimum, t_list **mylst)
{
	ft_push(&mystruct->stacka, &mystruct->stackb);
	ft_addto_lst(mylst, "pb");
	ft_push(&mystruct->stacka, &mystruct->stackb);
	ft_addto_lst(mylst, "pb");
	ft_sortthree(mystruct, mylst);
	while (mystruct->stackb.stacksize_curt > 0)
	{
		*minimum = ft_opcount(&mystruct->stacka, &mystruct->stackb);
		ft_sortfreal(&mystruct->stacka, &mystruct->stackb, minimum, mylst);
	}
	mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
}

//this function sorts the stacks for 5 numbers
void	ft_sortfive(t_p_s *mystruct, t_rotationnbr *minimum, t_list **mylst)
{
	bool	worststructure;

	worststructure = ft_worstpos(&mystruct->stacka);
	if (worststructure == true)
		ft_sortworst(mystruct, minimum, mylst);
	else
		ft_sortnormal(mystruct, minimum, mylst);
}

//this function differentiates between how many numbers are being given
//to the program and processes them accordingly with different functions.
void	ft_sort8size(t_p_s *mystruct, t_rotationnbr *minimum, t_list **mylst)
{
	if (ft_issorted(&mystruct->stacka) == true)
		mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
	else if (mystruct->stacka.stacksize_curt <= 1)
		return ;
	else if (mystruct->stacka.stacksize_curt == 2)
		mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
	else if (mystruct->stacka.stacksize_curt == 3)
		ft_sortthree(mystruct, mylst);
	else if (mystruct->stacka.stacksize_curt <= 5)
		ft_sortfive(mystruct, minimum, mylst);
	else
	{
		ft_push_all(&mystruct->stacka, &mystruct->stackb, mylst);
		while (mystruct->stackb.stacksize_curt > 0)
		{
			*minimum = ft_opcount(&mystruct->stacka, &mystruct->stackb);
			ft_sortfreal(&mystruct->stacka, &mystruct->stackb, minimum, mylst);
		}
		mystruct->stacka = ft_sorta(&mystruct->stacka, mylst);
	}
}
