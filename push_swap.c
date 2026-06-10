/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 08:06:32 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 14:56:59 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/* DONE
	 * 	VALIDATE INTEGER FROM INPUT: OK
	 * 	VALIDATE STRATEGY SELECTOR / BENCHMARK MODE FROM INPUT (--options) OK
	 * 	POPULATE DATA STRUCTURE WITH INPUT: LIST OR ARRAY ? OK
	 * 	IMPLEMENT BASIC PUSH_SWAP OPERATIONS OK
	 * 	IMPLEMENT DISORDER CALCULATOR OK
	 *
	 * TODO
	 * 		Learn to use exit()
	 * 	CHOOSE SORTING ALGORITHMS AND IMPLEMENT THEM
	 * 	IMPLEMENT ADAPTIVE ALGORITHM
	 * 	IMPLEMENT STRATEGY SELECTOR
	 * 	IMPLEMENT BENCHMARK MODE
	 * 	IMPLEMENT PRINTING FUNCTION
	 *
	 * 	BONUS:
	 * 		IMPLEMENT A CHECKER
	 * 			VALIDATE INPUT
	 * 			FUCNTION TO APPLY OPERATIONS ON THE INPUT
	 *
	 */

// excluir

#include <stdio.h>

static void	test_sorting(t_dlist **a, t_dlist **b, size_t (*f)(t_dlist **, \
			t_dlist **));

// excluir

int	main(int argc, char **argv)
{
	t_stack	a;
	t_dlist	*a_cpy;
	t_stack	b;
	t_opt	op;

	if (argc == 1 || !validate_store_input(argv, &op, &a.head))
		return (0);
	a.tail = ft_dlist_last(a.head);
	a.size = ft_dlist_size(a.head);
	b.head = NULL;
	b.tail = NULL;
	b.size = 0;

	float	disorder = compute_disorder(a.head);
	printf("Input Disorder: %.2f\n\n", disorder);

	printf("\t-- BUBBLE SORT --\n");
	a_cpy = ft_dlist_dup(a.head);
	test_sorting(&a.head, &b.head, &bubble);
	ft_dlist_clear(&a.head, &free);

	printf("\n\t-- INSERTION SORT --\n");
	a.head = ft_dlist_dup(a_cpy);
	test_sorting(&a.head, &b.head, &insertion);
	ft_dlist_clear(&a_cpy, &free);

	ft_dlist_clear(&a.head, &free);
	return (0);
}

static void	test_sorting(t_dlist **a, t_dlist **b, size_t (*f)(t_dlist **, \
			t_dlist **))
{
	size_t	operations_count;
	float	disorder;
	t_dlist	*tmp;

	operations_count = f(a, b);
	disorder = compute_disorder(*a);
	printf("Sorted Disorder: %.2f\nNumber of operations: %zu\n\n", \
			disorder, operations_count);
	printf("Sorted List: ");

	tmp = *a;
	while (tmp)
	{
		printf("%i ", *((int *)tmp->data));
		tmp = tmp->next;
	}
	printf("\n");
}
