#include "checker.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*elem;

	elem = ft_lstpop(a);
	if (*b == NULL)
		*b = elem;
	else
		ft_lstpush(b, elem);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*elem;

	elem = ft_lstpop(b);
	if (*a == NULL)
		*a = elem;
	else
		ft_lstpush(a, elem);
}
