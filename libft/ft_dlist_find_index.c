/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_find_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:23:15 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 10:31:35 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlist_find_index(t_dlist *begin_list, void *data_ref, int (*cmp)())
{
	int	i;

	i = 0;
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			return (i);
		i++;
		begin_list = begin_list->next;
	}
	return (-1);
}
