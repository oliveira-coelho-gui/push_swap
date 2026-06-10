/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:21:01 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 13:08:00 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	insert_in_place(t_dlist **a, t_dlist **b);

size_t	insertion(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;

	operation_count = 0;
	while (compute_disorder(*a) > 0.00001f)
	{
		while(*a)
		{
			if (!*b)
				operation_count += push(b, a);
			else if (!(*b)->next)
			{
				operation_count += push(b, a);
				if (*((int *)(*b)->data) < *((int *)(*b)->next->data))
					operation_count += swap(b);
			}
			else
				operation_count += insert_in_place(a, b);
		}
		while (*b)
			operation_count += push(a, b);
	}
	return (operation_count);
}

static size_t	insert_in_place(t_dlist **a, t_dlist **b)
{
	int		rotations;
	size_t	operation_count;
	int		i;

	rotations = ft_dlist_find_index(*b, (*a)->data, &less_than);
	operation_count = 0;
	i = -1;
	while (++i < rotations)
		operation_count += rotate(b);
	operation_count += push(b, a);
	while (i-- > 0)
		operation_count += reverse_rotate(b);
	if (rotations == -1)
		operation_count += rotate(b);
	return (operation_count);
}
