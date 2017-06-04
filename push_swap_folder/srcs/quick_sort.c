#include "push_swap.h"

void			quick_sort(t_list **a, t_list **b, size_t length_a)
{
	int		median;

	if (length_a == 2)
	{
		if (!stack_sorted(*a))
			swap_a(a, b);
		return ;
	}
	median = find_median(*a, length_a);  //length_a / 2 + length_a % 2-th element
	for each element in list a
		if nbr(element) < median
			push_b
		else
			rotate_a
	for length_a / 2 + length_a % 2 + 1 times
		reverse_rotate_a
		if (pre_top == median)
			swap_a
	for each element in list b
		push_a
	quick_sort(length_a / 2 + length_a % 2 - 1)
	for length_a / 2 + length_a % 2 times
	quick_sort(length_a / 2 + length_a % 2)
}
