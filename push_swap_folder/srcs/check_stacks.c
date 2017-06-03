/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:05:02 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 17:05:30 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				stack_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (nbr(lst) < nbr(lst->next))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int				check_stacks(t_list *a, t_list *b)
{
	if (b != NULL)
		return (0);
	if (!stack_sorted(a))
		return (0);
	return (1);
}
