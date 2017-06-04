#include "push_swap.h"

void			three_sort(t_list **a)
{
	t_list	*top;
	t_list	*bottom;

	while (!stack_sorted(*a))
	{
		top = (*a)->next->next;
		bottom = (*a);
		if (nbr(bottom) > nbr(top))
			swap_a(a, NULL);
		else
			rotate_a(a, NULL);
	}
}

void			min_to_top(t_list **a, size_t length_a)
{
	t_list		*lst;
	size_t		i;
	size_t		i_min;
	size_t		diff;
	int		min;

	i = 1;
	i_min = 1;
	lst = *a;
	min = nbr(lst);
	while (lst)
	{
		if (nbr(lst) < min)
		{
			min = nbr(lst);
			i_min = i;
		}
		lst = lst->next;
		i++;
	}
	i = 0;
	diff = length_a - i_min;
//	ft_printfnl("length_a %d, min %d, i_min %d, diff %d", length_a, min, i_min, diff);
	if (i_min < length_a / 2)
		while (i++ < length_a - diff)
			reverse_rotate_a(a, NULL);
	else
		while (i++ < diff)
			rotate_a(a, NULL);
}

void			simple_sort(t_list **a, t_list **b, size_t length_a)
{
	size_t		i;

	i = 0;
	while (i < length_a - 3)
	{
		min_to_top(a, length_a - i);
		push_b(a, b);
		i++;
	}
	three_sort(a);
	i = 0;
	while (i++ < length_a - 3)
		push_a(a, b);
}
