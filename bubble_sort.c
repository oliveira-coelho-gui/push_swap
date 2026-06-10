/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:24:09 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 08:05:20 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	bubble(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;

	operation_count = 0;
	while (compute_disorder(*a) > 0.00001f)
	{
		while((*a)->next)
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
		}
		while((*b)->next)
		{
			if (*((int *)(*b)->data) < *((int *)(*b)->next->data))
				operation_count += swap(b);
			operation_count += push(a, b);
		}
		operation_count += push(a, b);
	}
	return (operation_count);
}
