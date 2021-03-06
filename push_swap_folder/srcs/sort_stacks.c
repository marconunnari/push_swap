/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:52:36 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 18:55:50 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				nbr(t_list *listptr)
{
	return (*((int*)listptr->content));
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
		three_sort(a);
	else if (length_a <= 40)
		simple_sort(a, b, length_a);
	else
		quick_sort_a(a, b, length_a, 1);
}
