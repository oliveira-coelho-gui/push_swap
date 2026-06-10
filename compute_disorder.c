/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:04:50 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 14:53:41 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_dlist *lst)
{
	int		mistakes;
	int		total_pairs;
	t_dlist	*element1;
	t_dlist	*element2;

	mistakes = 0;
	total_pairs = 0;
	element1 = lst;
	if (!lst)
		return (1);
	while (element1->next)
	{
		element2 = element1->next;
		while (element2)
		{
			total_pairs += 1;
			if (*((int *)element1->data) > *((int *)element2->data))
				mistakes += 1;
			element2 = element2->next;
		}
		element1 = element1->next;
	}
	if (!total_pairs)
		return (0);
	return ((mistakes * 1.0) / total_pairs);
}
