/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:17:11 by jzhou             #+#    #+#             */
/*   Updated: 2021/10/02 13:00:15 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
//# include <stdio.h>

# define INFINITY 2147483647

//this struct counts how many times
//each rotational operation is being used
//and stores the sum of these operations for later comparisons.
typedef struct s_rotationnbr
{
	int	ra_amount;
	int	rb_amount;
	int	rr_amount;
	int	rra_amount;
	int	rrb_amount;
	int	rrr_amount;
	int	sum;

}	t_rotationnbr;

//this struct stores the values needed to create the stacks
typedef struct s_stack
{
	int	stacksize_fst;
	int	stacksize_curt;
	int	*actualstack;

}	t_stack;

//this struct stores two stacks in itself
typedef struct s_p_s
{
	t_stack	stacka;
	t_stack	stackb;

}	t_p_s;

//main file
void			ft_destructstr(char **strinput);
void			ft_readargs(int argc, char **argv, t_p_s *mystruct);
void			ft_fillstacka(int argc, char **argv, t_p_s *mystruct);
void			ft_init_stack(t_p_s *mystruct);

//push_swap_functions
void			ft_rotate(t_stack *actualstack);
void			ft_revrotate(t_stack *actualstack);
void			ft_swap(t_stack *actualstack);
void			ft_push(t_stack *from, t_stack *to);

//preparational steps for the actual sort, ft_preparesort.c
void			ft_push_all(t_stack *from, t_stack *to, t_list **mylst);
bool			ft_issorted(t_stack *stack);
bool			ft_simulatesort(t_stack *from, t_stack *to);
int				ft_smallestnbr(t_stack *actualstack);
bool			ft_worstpos(t_stack *actualstack);

//sort after size
void			ft_sortthree(t_p_s *mystruct, t_list **mylst);
void			ft_sortfive(t_p_s *mystruct, t_rotationnbr *minimum,
					t_list **mylst);
void			ft_sort8size(t_p_s *mystruct, t_rotationnbr *minimum,
					t_list **mylst);

//ft_sortstack.c
t_stack			ft_sorta(t_stack *stacka, t_list **mylst);
t_stack			ft_sortb(t_stack *stackb, t_list **mylst);
void			ft_addto_lst(t_list **lst, char *str);
void			ft_resetrotatea(t_stack *stacka, t_rotationnbr *current);

// Debugging functions, delete them later, display operations
//void			ft_printStack(t_stack *actualstack);
//void			ft_displaystk(t_stack *actualstack);
//void			ft_printAandB(t_p_s *mystruct);
void			ft_print_op(t_list *mylst);

//error handling
int				ft_checkdigit(char *str);
int				ft_maxvalue(char *str);
int				ft_checkdouble(t_stack *stack);

//sort for real + efficiency check, ft_efficiency.c
t_rotationnbr	ft_opcount(t_stack *stacka, t_stack *stackb);
void			ft_sortfreal(t_stack *stacka, t_stack *stackb,
					t_rotationnbr *minimum, t_list **mylst);

//ft_best_way.c and ft_leastsum.c
int				ft_leastsum(t_stack stacka, t_stack stackb,
					t_rotationnbr current);
t_rotationnbr	ft_best_way(t_stack stacka, t_stack stackb,
					t_rotationnbr *current);

//compare minimum, ft_minimumop.c
int				ft_minrr(t_rotationnbr minimum);
int				ft_minrrr(t_rotationnbr minimum);
t_rotationnbr	ft_comparemin(t_rotationnbr *min, t_rotationnbr *cur);

#endif
