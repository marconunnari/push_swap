#include "checker.h"

void	rotate_list(t_list **list)
{
	t_list	*last;

	last = ft_lstpop(list);
	ft_lstadd(list, last);
}

void	rotate_a(t_list **a, t_list **b)
{
	(void)b;
	rotate_list(a);
}

void	rotate_b(t_list **a, t_list **b)
{
	(void)a;
	rotate_list(b);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate_list(a);
	rotate_list(b);
}
