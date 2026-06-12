/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:44:55 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/12 13:51:46 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dlist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (*((int *)lst->data) > *((int *)lst->next->data))
			return (0);
		lst = lst->next;
	}
	return (1);
}
