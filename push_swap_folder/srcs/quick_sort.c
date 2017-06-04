#include "push_swap.h"

static void		partition(t_list **a, t_list **b,
		size_t len_a, int median)
{
	size_t		i;
	int		n;

	i = 0;
	while (i++ < len_a)
	{
		n = nbr(*a);
		reverse_rotate_a(a, b);
		if (n <= median)
			push_b(a, b);
		if (n == median)
			rotate_b(a, b);
	}
	reverse_rotate_b(a, b);
	while (*b)
		push_a(a, b);
	i = 0;
	while (i++ < len_a)
		rotate_a(a, b);
}

void			quick_sort_2(t_list **a, t_list **b)
{
	if (nbr(*a) > nbr((*a)->next))
		return ;
	reverse_rotate_a(a, b);
	reverse_rotate_a(a, b);
	swap_a(a, b);
	rotate_a(a, b);
	rotate_a(a, b);
}

void			quick_sort(t_list **a, t_list **b, size_t len_a)
{
	size_t		i;
	int		median;
	size_t		len_smallers;
	size_t		len_biggers;

	if (len_a < 2)
		return ;
	if (len_a == 2)
		return quick_sort_2(a, b);
	median = find_median(*a, len_a);
	partition(a, b, len_a, median);
	if (len_a == 3)
		return ;
	len_biggers = len_a / 2;
	quick_sort(a, b, len_biggers);
	i = 0;
	while (i++ < (len_biggers) + 1)
		reverse_rotate_a(a, b);
	len_smallers = (len_a - 1) / 2;
	quick_sort(a, b, len_smallers);
	i = 0;
	while (i++ < (len_biggers) + 1)
		rotate_a(a, b);
}
