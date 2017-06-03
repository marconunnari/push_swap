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

int			islittle(t_list *lst)
{
	size_t		res;

	res = 0;
	while(lst)
	{
		res++;
		if (res >= 7)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void			sort_stacks(t_list **a, t_list **b)
{
	if (is_little(*a))
		insertion_sort(a, b);
	else
		quick_sort(a, b);
}
