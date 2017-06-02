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

void			sort_a(t_list **a, t_list **b, int len_a)
{
	t_list	*st;
	int		min;
	int		i_min;
	int		i;

	if (stack_sorted(*a))
		return ;
	st = *a;
	min = nbr(st);
	i_min = 0;
	i= 0;
	while (st)
	{
		if (nbr(st) < min)
		{
			min = nbr(st);
			i_min = i;
		}
		i++;
		st = st->next;
	}
	if (i_min == len_a - 1)
		push_b(a, b);
	else if (i_min >= len_a / 2)
		rotate_a(a, b);
	else
		reverse_rotate_a(a, b);
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
		else
			sort_a(a, b, len_a);
		if (len_b > 0 && stack_sorted(*a))
			push_a(a, b);
	}
}
