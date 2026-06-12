/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:24:09 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/12 13:57:14 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	regular_bubble(t_dlist **a, t_dlist **b);
static size_t	reverse_bubble(t_dlist **a, t_dlist **b);

size_t	bubble(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;

	operation_count = 0;
	while (!is_sorted(*a))
	{
		operation_count += regular_bubble(a, b);
		operation_count += reverse_bubble(a, b);
	}
	return (operation_count);
}

static size_t	regular_bubble(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;

	operation_count = 0;
	while ((*a)->next)
	{
		if (*((int *)(*a)->data) > *((int *)(*a)->next->data))
			operation_count += swap(a, 'a');
		operation_count += push(b, a, 'b');
	}
	return (operation_count);
}

static size_t	reverse_bubble(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;

	operation_count = 0;
	while ((*b)->next)
	{
		if (*((int *)(*b)->data) < *((int *)(*b)->next->data))
			operation_count += swap(b, 'b');
		operation_count += push(a, b, 'a');
	}
	operation_count += push(a, b, 'a');
	return (operation_count);
}
