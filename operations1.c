/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:43:28 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/09 19:37:26 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dlist **stack)
{
	t_dlist	*second;
	t_dlist	*first;

	if (*stack && (*stack)->next)
	{
		first = ft_dlist_pop(stack);
		second = ft_dlist_pop(stack);
		ft_dlist_push_front_elem(stack, first);
		ft_dlist_push_front_elem(stack, second);
	}
	return (1);
}

int	swap_both(t_dlist **stack1, t_dlist **stack2)
{
	swap(stack1);
	swap(stack2);
	return (1);
}

int	push(t_dlist **dest, t_dlist **src)
{
	t_dlist	*node;

	if (*src)
	{
		node = ft_dlist_pop(src);
		ft_dlist_push_front_elem(dest, node);
	}
	return (1);
}
