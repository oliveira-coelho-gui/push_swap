/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 07:30:18 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/12 11:34:26 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_dlist **dlst, int c)
{
	t_dlist	*first;

	if (*dlst && (*dlst)->next)
	{
		first = ft_dlist_pop(dlst);
		ft_dlist_push_back_elem(dlst, first);
	}
	if (c == -1)
		ft_printf("r");
	else
		ft_printf("r%c\n", c);
	return (1);
}

int	rotate_both(t_dlist **dlst1, t_dlist **dlst2)
{
	rotate(dlst1, -1);
	rotate(dlst2, -1);
	ft_printf("\n");
	return (1);
}

int	reverse_rotate(t_dlist **dlst, int c)
{
	t_dlist	*last;

	if (*dlst && (*dlst)->next)
	{
		last = ft_dlist_pop_end(dlst);
		ft_dlist_push_front_elem(dlst, last);
	}
	if (c == -1)
		ft_printf("r");
	else
		ft_printf("rr%c\n", c);
	return (1);
}

int	reverse_rotate_both(t_dlist **dlst1, t_dlist **dlst2)
{
	reverse_rotate(dlst1, -1);
	reverse_rotate(dlst2, -1);
	ft_printf("r\n");
	return (1);
}
