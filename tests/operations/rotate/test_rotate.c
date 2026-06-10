/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:39:07 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/10 13:37:45 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	print_num(void *n);
static void	test_rotate(t_dlist **a);
static void	test_push(t_dlist **b, t_dlist **a);

int main(int argc, char **argv)
{
	t_opt	op;
	t_dlist *a;
	t_dlist *b = NULL;

	if (argc == 1)
		return (0);
	validate_store_input(argv, &op, &a);
//	ft_dlist_foreach(a, &print_num);
//	printf("\n");
//	t_dlist *tmp = a;
//	for (int i = 0; tmp; i++, tmp = tmp->next)
//	{
//		printf("a = %p\na->next = %p\na->prev = %p\nnum = %i\n", tmp, tmp->next, tmp->prev, *(int *)(tmp->data));
//	}
	test_rotate(&a);
	//ft_dlist_foreach(a, &print_num);
	//printf("\n");
	//tmp = a;
	//for (int i = 0; tmp; i++, tmp = tmp->next)
	//{
	//	printf("a = %p\na->next = %p\na->prev = %p\nnum = %i\n", tmp, tmp->next, tmp->prev, *(int *)(tmp->data));
	//}
	test_rotate(&a);
	test_rotate(&a);
	test_push(&b, &a);
	test_push(&b, &a);
	test_push(&b, &a);
	op.bench = 0;
	ft_dlist_clear(&a, &free);
	ft_dlist_clear(&b, &free);
	return (0);
}

static void	print_num(void *n)
{
	printf("%i ", *((int *)n));
}

static void	test_rotate(t_dlist **a)
{
	rotate(a);
	ft_dlist_foreach(*a, &print_num);
	printf("\n");
}


static void	test_push(t_dlist **b, t_dlist **a)
{
	push(b, a);
	ft_dlist_foreach(*a, &print_num);
	printf("\n");
	ft_dlist_foreach(*b, &print_num);
	printf("\n");
}

