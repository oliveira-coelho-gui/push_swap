#include "push_swap.h"

size_t	selection(t_dlist **a, t_dlist **b)
{
	size_t	operation_count;
	int	n;
	t_dlist	*smallest;
	size_t	i;

	operation_count = 0;
	while (compute_disorder(*a) > 0.00001f)
	{
		while (*a)
		{
			i = 0;
			n = INT_MAX;
			while (ft_dlist_find(*a, &n, less_than))
			{
				smallest = ft_dlist_find(*a, &n, less_than);
				n = *((int *)(smallest->data));
			}
			i = ft_dlist_find_index(*a, &n, equals);
			while (i--)
				operation_count += rotate(a);
			operation_count += push(b, a);
		}
		while (*b)
		{
			operation_count += push(a, b);

		}
	}
	return (operation_count);
}
