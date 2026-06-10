/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_integer_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:29:56 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 11:36:37 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicates(char **argv, int i, t_dlist **lst);

int	valid_integer_input(char **argv, int i, t_dlist **lst)
{
	int		tmp_i;
	long	num;

	tmp_i = i;
	while (argv[i])
	{
		if (!str_is_num(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	if (duplicates(argv, tmp_i, lst))
		return (0);
	(*lst)->prev = ft_dlist_last(*lst);
	return (1);
}

int	str_is_num(char *str)
{
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}

static int	duplicates(char **argv, int i, t_dlist **lst)
{
	int		*num;

	while (argv[i])
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(argv[i]);
		if (!*lst || !ft_dlist_find(*lst, num, &equals))
			ft_dlist_push_back(lst, num);
		else
		{
			free (num);
			ft_dlist_clear(lst, &free);
			return (1);
		}
		i++;
	}
	return (0);
}
