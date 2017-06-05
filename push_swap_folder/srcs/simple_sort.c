/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 19:23:58 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 19:08:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				get_i_min(t_list *lst)
{
	size_t		i;
	size_t		i_min;
	int			min;

	i = 1;
	i_min = 1;
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
	return (i_min);
}

void			min_to_top(t_list **a, size_t length_a)
{
	t_list		*lst;
	size_t		i;
	size_t		i_min;

	lst = *a;
	i_min = get_i_min(lst);
	i = 0;
	if (i_min < length_a / 2)
		while (i++ < i_min)
			reverse_rotate_a(a, NULL);
	else
		while (i++ < length_a - i_min)
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
