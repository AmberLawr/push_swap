/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:17:11 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/28 19:25:04 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# define INFINITY 2147483647

// DELETE ME
# include <stdio.h>
# define PRINT_HERE() (printf("line %d, file %s\n", __LINE__, __FILE__))

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

typedef struct s_stack
{
	int	stacksize_fst;
	int	stacksize_curt;
	int	*actualstack;

}	t_stack;

typedef struct s_p_s
{
	t_stack	stacka;
	t_stack stackb;

}	t_p_s;

//main file
void	ft_destructstr(char **strinput);
void	ft_readargs (int argc, char **argv, t_p_s *mystruct);
void	ft_fillstacka(int argc, char **argv, t_p_s *mystruct);
void	ft_init_stack(t_p_s *mystruct);

//preparational steps for the actual sort
void	ft_push_all(t_stack *from, t_stack *to);
bool	ft_pushable(t_stack *from, t_stack *to);
bool	ft_issorted(t_stack *stack);
bool	ft_simulatesort(t_stack *from, t_stack *to);
int		ft_smallestnbr(t_stack *actualstack);

//push_swap_functions
void	ft_rotate(t_stack *actualstack);
void	ft_revrotate(t_stack *actualstack);
void	ft_swap(t_stack *actualstack);
void	ft_push(t_stack *from, t_stack *to);
int		ft_sortstack(t_stack *actualstack);

// Debugging functions, delete them later
void	ft_printStack(t_stack *actualstack);
void	ft_displaystk(t_stack *actualstack);
void	ft_printAandB(t_p_s *mystruct);

//errors
int		ft_checkdigit(char *str);
int		ft_maxvalue(char *str);
int		ft_checkdouble(t_stack *stack);

//operations history + sort for real + efficiency check
void			ft_addto_lst(t_list **lst, char *str);
void			ft_resetrotatea(t_stack *stacka, t_rotationnbr *current);
void			ft_resetrotateb(t_stack *stackb, t_rotationnbr *current);
t_rotationnbr	ft_opcount(t_stack *stacka, t_stack *stackb);
void			ft_sortfreal(t_stack *stacka, t_stack *stackb, t_rotationnbr *minimum, t_list	*mylst);

int				ft_leastsum(t_stack stacka, t_stack stackb, t_rotationnbr current);
t_rotationnbr	ft_best_way(t_stack stacka, t_stack stackb, t_rotationnbr *current);

//compare minimum
int				ft_minrr(t_rotationnbr minimum);
int				ft_minrrr(t_rotationnbr minimum);
t_rotationnbr	ft_comparemin(t_rotationnbr *min, t_rotationnbr *cur);
t_stack 		ft_sorta(t_stack *stacka, t_list *mylst);

#endif
