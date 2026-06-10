/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:12:45 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/09 17:47:47 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_pop(t_dlist **stack)
{
	t_dlist	*first;

	first = *stack;
	if (first)
	{
		*stack = first->next;
		if (*stack)
			(*stack)->prev = NULL;
		first->next = NULL;
		first->prev = NULL;
	}
	return (first);
}
