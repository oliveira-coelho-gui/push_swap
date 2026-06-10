/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pop_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 07:15:49 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/09 17:45:40 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_pop_end(t_dlist **dlst)
{
	t_dlist	*end;

	if (*dlst)
	{
		if ((*dlst)->next)
		{
			end = ft_dlist_last(*dlst);
			end->prev->next = NULL;
		}
		else
		{
			end = *dlst;
			*dlst = NULL;
		}
		end->next = NULL;
		end->prev = NULL;
	}
	return (end);
}
