/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:52:36 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 19:14:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			nbr(t_list *listptr)
{
	return (*((int*)listptr->content));
}

void			sort_three(t_list **a)
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

void			sort_simple(t_list **a, t_list **b, size_t length_a)
{
	size_t		i;

	i = 0;
	while (i < length_a - 3)
	{
		min_to_top(a, length_a - i);
		push_b(a, b);
		i++;
	}
	sort_three(a);
	i = 0;
	while (i++ < length_a - 3)
		push_a(a, b);
}

void			sort_stacks(t_list **a, t_list **b)
{
	size_t	length_a;

	if (check_stacks(*a, *b))
		return ;
	length_a = ft_lstlen(*a);
	if (length_a == 2)
		swap_a(a, NULL);
	else if (length_a == 3)
		sort_three(a);
	else if (length_a < 24)
		sort_simple(a, b, length_a);
	else {};
		//quick_sort(a, b);
}
