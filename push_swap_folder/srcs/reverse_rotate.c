/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:19:38 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 15:52:54 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_list(t_list **list)
{
	t_list	*first;

	first = ft_lstshift(list);
	ft_lstpush(list, first);
}

void	reverse_rotate_a(t_list **a, t_list **b)
{
	(void)b;
	reverse_rotate_list(a);
	ft_printfnl("rra");
}

void	reverse_rotate_b(t_list **a, t_list **b)
{
	(void)a;
	reverse_rotate_list(b);
	ft_printfnl("rrb");
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate_list(a);
	reverse_rotate_list(b);
	ft_printfnl("rrr");
}
