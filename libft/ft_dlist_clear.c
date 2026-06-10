/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:12:37 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 11:32:34 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_clear(t_dlist **begin_list, void (*free_fct)(void *))
{
	t_dlist	*tmp;

	while (*begin_list)
	{
		if ((*begin_list)->data)
			free_fct((*begin_list)->data);
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
}
