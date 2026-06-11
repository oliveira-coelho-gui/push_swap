/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:24:09 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 19:54:08 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	regular_bubble(t_dlist **a, t_dlist **b, \
		size_t size, size_t *i);
static size_t	reverse_bubble(t_dlist **a, t_dlist **b, \
		size_t size, size_t *i);

size_t	bubble(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;
	size_t	lst_size;
	size_t	iter;

	lst_size = ft_dlist_size(*a);
	operation_count = 0;
	iter = 1;
	while (compute_disorder(*a) > 0.00001f)
	{
		operation_count += regular_bubble(a, b, lst_size, &iter);
		operation_count += reverse_bubble(a, b, lst_size, &iter);
	}
	return (operation_count);
}

static size_t	regular_bubble(t_dlist **a, t_dlist **b, \
		size_t size, size_t *i)
{
	size_t	operation_count;
	size_t	iter;

	operation_count = 0;
	iter = 0;
	while ((*a)->next && iter < size - *i)
	{
		if (*((int *)(*a)->data) > *((int *)(*a)->next->data))
		{
			if ((*b) && (*b)->next && \
					*((int *)(*b)->data) < *((int *)(*b)->next->data))
				operation_count += swap_both(a, b);
			else
				operation_count += swap(a);
		}
		operation_count += push(b, a);
		iter++;
	}
	(*i)++;
	return (operation_count);
}

static size_t	reverse_bubble(t_dlist **a, t_dlist **b, \
		size_t size, size_t *i)
{
	size_t	operation_count;
	size_t	iter;

	operation_count = 0;
	iter = 0;
	while ((*b)->next && iter < size - *i)
	{
		if (*((int *)(*b)->data) < *((int *)(*b)->next->data))
		{
			if ((*a) && (*a)->next && \
					*((int *)(*a)->data) > *((int *)(*a)->next->data))
				operation_count += swap_both(a, b);
			else
				operation_count += swap(b);
		}
		operation_count += push(a, b);
		iter++;
	}
	operation_count += push(a, b);
	(*i)++;
	return (operation_count);
}
