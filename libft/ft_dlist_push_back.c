/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:38:54 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/03 07:18:31 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_push_back(t_dlist **begin_list, void *data)
{
	t_dlist	*last;
	t_dlist	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!*begin_list)
		*begin_list = new;
	else
	{
		last = ft_dlist_last(*begin_list);
		last->next = new;
		new->prev = last;
	}
}
