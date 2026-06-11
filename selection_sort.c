/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:52:46 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 19:53:29 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	selection(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;
	int		smallest;
	size_t	i;

	operation_count = 0;
	while (compute_disorder(*a) > 0.00001f)
	{
		while (*a)
		{
			smallest = INT_MAX;
			while (ft_dlist_find(*a, &smallest, less_than))
				smallest = *((int *)(ft_dlist_find(*a, \
								&smallest, less_than))->data);
			i = ft_dlist_find_index(*a, &smallest, equals);
			while (i--)
				operation_count += rotate(a);
			operation_count += push(b, a);
		}
		while (*b)
			operation_count += push(a, b);
	}
	return (operation_count);
}
