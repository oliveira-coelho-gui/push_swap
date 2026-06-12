/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:43:28 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/12 13:41:35 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dlist **stack, int c)
{
	t_dlist	*second;
	t_dlist	*first;

	if (*stack && (*stack)->next)
	{
		first = ft_dlist_pop(stack);
		second = ft_dlist_pop(stack);
		ft_dlist_push_front_elem(stack, first);
		ft_dlist_push_front_elem(stack, second);
		if (c == -1)
			ft_printf("s");
		else
			ft_printf("s%c\n", c);
		return (1);
	}
	else
		return (0);
}

int	swap_both(t_dlist **stack1, t_dlist **stack2)
{
	if (!*stack1 && !*stack2)
		return (0);
	if (*stack1)
		swap(stack1, -1);
	else
		ft_printf("s");
	if (*stack2)
		swap(stack2, -1);
	else
		ft_printf("s");
	ft_printf("\n");
	return (1);
}

int	push(t_dlist **dest, t_dlist **src, int c)
{
	t_dlist	*node;

	if (*src)
	{
		node = ft_dlist_pop(src);
		ft_dlist_push_front_elem(dest, node);
		ft_printf("p%c\n", c);
		return (1);
	}
	else
		return (0);
}
