/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_backs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:25:21 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 10:26:10 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_than(int *n1, int *n2)
{
	if (*n1 > *n2)
		return (0);
	return (1);

}

int	less_than(int *n1, int *n2)
{
	if (*n1 < *n2)
		return (0);
	return (1);

}

int	equals(int *n1, int *n2)
{
	if (*n1 == *n2)
		return (0);
	return (1);
}

