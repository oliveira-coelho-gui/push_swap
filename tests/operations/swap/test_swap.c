#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	print_num(void *n);
void	test_swap(t_dlist **a);
void	test_push(t_dlist **b, t_dlist **a);

int main(int argc, char **argv)
{
	t_opt	op;
	t_dlist *a;
	//t_dlist *b = NULL;

	if (argc == 1)
		return (0);
	validate_store_input(argv, &op, &a);

	//ft_dlist_foreach(a, &print_num);
	//printf("\n");
	//t_dlist *tmp = a;
	//for (int i = 0; tmp; i++, tmp = tmp->next)
	//	printf("a = %p\na->next = %p\na->prev = %p\nnum = %i\n", tmp, tmp->next, tmp->prev, *(int *)(tmp->data));

	//printf("\n");
	test_swap(&a);

	//tmp = a;
	//for (int i = 0; tmp; i++, tmp = tmp->next)
	//	printf("a = %p\na->next = %p\na->prev = %p\nnum = %i\n", tmp, tmp->next, tmp->prev, *(int *)(tmp->data));

	//printf("\n");
	//test_push(&b, &a);
	op.bench = 0;
	ft_dlist_clear(&a, &free);
	return (0);
}

static void	print_num(void *n)
{
	printf("%i ", *((int *)n));
}

void	test_swap(t_dlist **a)
{
	swap(a);
	ft_dlist_foreach(*a, &print_num);
	printf("\n");
}

void	test_push(t_dlist **b, t_dlist **a)
{
	push(b, a);
	ft_dlist_foreach(*a, &print_num);
	ft_dlist_foreach(*b, &print_num);
	printf("\n");
}
