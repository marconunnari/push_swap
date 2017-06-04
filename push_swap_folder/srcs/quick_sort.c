#include "push_swap.h"

void			quick_sort(t_list **a, t_list **b, size_t length_a)
{
	size_t		i;
	t_list	*lst;
	int		median;
	t_list	*small_a;
	t_list	*big_a;

	ft_printfnl("quick sort of list starting with %d of len %d", nbr(*a), length_a);
	if (length_a == 2)
	{
		if (!stack_sorted(*a))
			swap_a(a, b);
		return ;
	}
	median = find_median(*a, length_a);  //length_a / 2 + 1-th element
	i = 0;
	while (i++ < length_a)
	{
		if (nbr(ft_lsttail(*a)) < median)
			push_b(a, b);
		else
			rotate_a(a, b);
	}
	i = 0;
	while (i++ < length_a / 2 + length_a % 2)
	{
		lst = ft_lsttail(*a);
		reverse_rotate_a(a, b);
		if (nbr(lst) == median)
			swap_a(a, b);
	}
	big_a = *a;
	push_a(a, b);
	small_a = ft_lsttail(*a);
	while (*b)
		push_a(a, b);
	if (length_a == 3)
		return ;
	quick_sort(&small_a, b, length_a / 2);
	i = 0;
	while (i++ < length_a / 2 + 1)
		rotate_a(a, b);
	quick_sort(&big_a, b, length_a / 2 + length_a % 2 - 1);
}
