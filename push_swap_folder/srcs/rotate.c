/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:19:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 15:44:29 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printfnl("ra");
}

void	rotate_b(t_list **a, t_list **b)
{
	(void)a;
	rotate_list(b);
	ft_printfnl("rb");
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate_list(a);
	rotate_list(b);
	ft_printfnl("rr");
}
