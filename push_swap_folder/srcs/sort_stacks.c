/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:52:36 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 18:49:23 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_a2(t_list **a)
{
	swap_a(a, NULL);
}

int				nbr(t_list *listptr)
{
	return (*((int*)listptr->content));
}

void			sort_a3(t_list **a)
{
	t_list	*st;
	int		bottom;
	int		middle;
	int		top;

	st = *a;
	top = nbr(st->next->next);
	middle = nbr(st->next);
	bottom = nbr(st);
	if (bottom > middle && bottom < top && middle < top)
		rotate_a(a, NULL);
	else if (bottom > middle && bottom > top && middle < top)
		swap_a(a, NULL);
	else if (bottom < middle && bottom > top && middle > top)
		swap_a(a, NULL);
	else if (bottom < middle && bottom < top && middle < top)
		rotate_a(a, NULL);
	else if (bottom < middle && bottom < top && middle > top)
		reverse_rotate_a(a, NULL);
}

void			sort_a4(t_list **a, t_list **b)
{
	t_list	*st;
	int		bottom;
	int		middle1;
	int		middle2;
	int		top;

	st = *a;
	top = nbr(st->next->next->next);
	middle1 = nbr(st->next->next);
	middle2 = nbr(st->next);
	bottom = nbr(st);
	if (top < middle1 && top < middle2 && top < bottom)
		push_b(a, b);
	else if (middle1 < top && middle1 < middle2 && middle1 < bottom)
		rotate_a(a, b);
	else if (bottom < top && bottom < middle1 && bottom < middle2)
		reverse_rotate_a(a, b);
	else if (middle2 < top && middle2 < middle1 && middle2 < bottom)
		rotate_a(a, b);
}

void			sort_a5(t_list **a, t_list **b)
{
	t_list	*st;
	int		bottom;
	int		middle1;
	int		middle2;
	int		middle3;
	int		top;

	st = *a;
	top = nbr(st->next->next->next->next);
	middle1 = nbr(st->next->next->next);
	middle2 = nbr(st->next->next);
	middle3 = nbr(st->next);
	bottom = nbr(st);
	if (top < middle1 && top < middle2 && top < bottom && top < middle3)
		push_b(a, b);
	if (middle1 < top && middle1 < middle2 && middle1 < bottom && middle1 < middle3)
		rotate_a(a, b);
	if (bottom < top && bottom < middle1 && bottom < middle2 && bottom < middle3)
		reverse_rotate_a(a, b);
	if (middle2 < top && middle2 < middle1 && middle2 < bottom)
		rotate_a(a, b);
}

size_t			ft_lstlen(t_list *lst)
{
	size_t		res;

	res = 0;
	while(lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}

void			sort_stacks(t_list **a, t_list **b)
{
	int		len_a;
	int		len_b;

	while(!check_stacks(*a, *b))
	{
		len_a = ft_lstlen(*a);
		len_b = ft_lstlen(*b);
		if (len_a == 2)
			sort_a2(a);
		else if (len_a == 3)
			sort_a3(a);
		else if (len_a == 4)
			sort_a4(a, b);
		if (len_b == 1 && stack_sorted(*a))
			push_a(a, b);
	}
}
