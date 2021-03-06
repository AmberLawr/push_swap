/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:29:17 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/01 20:29:17 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

int	ft_intlenbase(unsigned long nbr, int base)
{
	int	counter;

	if (nbr == 0)
		return (1);
	counter = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		counter++;
	}
	return (counter);
}
