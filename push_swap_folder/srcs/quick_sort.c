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
	ft_printfnl("push smallers in a");
	//sleep(3);
	reverse_rotate_b(a, b);
	while (*b)
		push_a(a, b);
	ft_printfnl("rotate to original position");
	//sleep(3);
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
		quick_sort_2(a, b);
	median = find_median(*a, len_a);
	ft_printfnl("partition, len_a %d, median: %d",len_a, median);
	//sleep(3);
	partition(a, b, len_a, median);
	if (len_a == 3)
		return ;
	ft_printfnl("sort biggers");
	//sleep(3);
	len_biggers = len_a / 2;
	quick_sort(a, b, len_biggers);
	ft_printfnl("put smallers at bottom");
	//sleep(3);
	i = 0;
	while (i++ < (len_biggers) + 1)
		reverse_rotate_a(a, b);
	ft_printfnl("sort smallers");
	//sleep(3);
	len_smallers = (len_a - 1) / 2;
	quick_sort(a, b, len_smallers);
	ft_printfnl("re-put smallers at top");
	//sleep(3);
	i = 0;
	while (i++ < (len_biggers) + 1)
		rotate_a(a, b);
}
