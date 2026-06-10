/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push_back_elem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:47:53 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/09 17:41:08 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_push_back_elem(t_dlist **begin_list, t_dlist *new)
{
	t_dlist	*current_end;

	if (new)
	{
		if (!*begin_list)
			*begin_list = new;
		else
		{
			current_end = ft_dlist_last(*begin_list);
			current_end->next = new;
			new->prev = current_end;
		}
	}
}
