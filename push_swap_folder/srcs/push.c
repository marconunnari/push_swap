/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:19:31 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 17:07:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*elem;

	elem = ft_lstpop(a);
	if (*b == NULL)
		*b = elem;
	else
		ft_lstpush(b, elem);
	ft_printfnl("pb");
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*elem;

	elem = ft_lstpop(b);
	if (*a == NULL)
		*a = elem;
	else
		ft_lstpush(a, elem);
	ft_printfnl("pa");
}
