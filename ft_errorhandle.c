/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorhandle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:59:27 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/12 13:54:20 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//these functions check for errors and are self-explanatory
int	ft_checkdigit(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-')
		index++;
	if (str[index] == '\0')
		return (-1);
	while (str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0)
			return (-1);
		index++;
	}
	return (0);
}

int	ft_maxvalue(char *str)
{
	if ((ft_atoi(str) == INT_MAX && ft_strncmp(str, "2147483647", 10) != 0)
		|| ((ft_strlen(str) > 10) && str[0] != '-'))
		return (-1);
	if ((ft_atoi(str) == INT_MIN && ft_strncmp(str, "-2147483648", 11) != 0)
		|| ((ft_strlen(str) > 11) && str[0] == '-'))
		return (-1);
	return (0);
}

int	ft_checkdouble(t_stack *stack)
{
	int	index;
	int	jindex;

	index = 0;
	while (index < stack->stacksize_curt - 1)
	{
		jindex = index + 1;
		while (jindex < stack->stacksize_curt)
		{
			if (stack->actualstack[index] == stack->actualstack[jindex])
				return (-1);
			jindex++;
		}
		index++;
	}
	return (0);
}
