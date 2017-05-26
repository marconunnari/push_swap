#include "checker.h"

void	reverse_rotate_list(t_list **list)
{
	t_list	*first;

	first = ft_lstshift(list);
	ft_lstpush(list, first);
}

void	reverse_rotate_a(t_list **a, t_list **b)
{
	(void)b;
	reverse_rotate_list(a);
}

void	reverse_rotate_b(t_list **a, t_list **b)
{
	(void)a;
	reverse_rotate_list(b);
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate_list(a);
	reverse_rotate_list(b);
}
