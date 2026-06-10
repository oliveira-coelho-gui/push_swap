/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:32:37 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/09 18:11:31 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_option(char *str, t_opt *op);
static int	valid_option_input(char **argv, t_opt *op);

int	validate_store_input(char **argv, t_opt *op, t_dlist **lst)
{
	int	after_op_i;

	after_op_i = valid_option_input(argv, op);
	if (!after_op_i)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!argv[after_op_i] || !valid_integer_input(argv, after_op_i, lst))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static int	valid_option_input(char **argv, t_opt *op)
{
	int	i;

	op->strategy = UNSET;
	op->strategy = UNSET;
	i = 1;
	while (argv[i] && !str_is_num(argv[i]))
	{
		if (!str_is_option(argv[i], op))
			return (0);
		i++;
	}
	return (i);
}

static int	str_is_option(char *str, t_opt *op)
{
	char	**strategy_selector;
	int		i;

	strategy_selector = (char *[])
	{
		"--simple", "--medium", "--complex", "--adaptive", NULL
	};
	i = 0;
	while (strategy_selector[i])
	{
		if (op->strategy)
			break ;
		if (!ft_strcmp(str, strategy_selector[i]))
		{
			op->strategy = i + 1;
			return (1);
		}
		i++;
	}
	if (!ft_strcmp(str, "--bench"))
	{
		op->bench = BENCH;
		return (1);
	}
	return (0);
}
