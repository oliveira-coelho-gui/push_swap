/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:19:10 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 11:21:50 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_map(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new_lst;
	t_dlist	*node;

	new_lst = NULL;
	while (lst)
	{
		node = ft_create_elem(f(lst->data));
		if (!node)
		{
			ft_dlist_clear(&new_lst, del);
			return (NULL);
		}
		ft_dlist_push_back_elem(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
