/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:28:48 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 22:23:01 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef enum e_option
{
	UNSET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_option;

typedef struct s_opt
{
	t_option	bench;
	t_option	strategy;
}	t_opt;

typedef struct s_stack
{
	t_dlist	*head;
	t_dlist	*tail;
	size_t	size;
}	t_stack;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

typedef struct s_operations
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_operations;

typedef struct	s_state
{
	float			disorder;
	t_opt			option;
	unsigned int	total_ops;
	t_operations	move;

}	t_state;

int		validate_store_input(char **argv, t_opt *op, t_dlist **lst);
int		valid_integer_input(char **argv, int i, t_dlist **lst);
int		str_is_num(char *str);
int		swap(t_dlist **stack, int c);
int		swap_both(t_dlist **stack1, t_dlist **stack2);
int		push(t_dlist **dest, t_dlist **src, int c);
int		rotate(t_dlist **dlst, int c);
int		rotate_both(t_dlist **dlst1, t_dlist **dlst2);
int		reverse_rotate(t_dlist **dlst, int c);
int		reverse_rotate_both(t_dlist **dlst1, t_dlist **dlst2);
float	compute_disorder(t_dlist *lst);
int		greater_than(int *n1, int *n2);
int		less_than(int *n1, int *n2);
int		equals(int *n1, int *n2);
size_t	bubble(t_dlist **a, t_dlist **b);
size_t	insertion(t_dlist **a, t_dlist **b);
size_t	selection(t_dlist **a, t_dlist **b);

#endif
