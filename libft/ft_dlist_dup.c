/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:10:14 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 11:50:12 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*data_dup(void *x);

t_dlist	*ft_dlist_dup(t_dlist *lst)
{
	return (ft_dlist_map(lst, data_dup, free));
}

static void	*data_dup(void *x)
{
	void	*n;

	n = (void *)malloc(sizeof(int));
	ft_memcpy(n, x, sizeof(int));
	return (n);
}
