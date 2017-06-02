/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:30:24 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 15:44:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list *lst)
{
	int		*x;
	int		*y;

	while (lst)
	{
		if (lst->next && !lst->next->next)
		{
			x = (int*)lst->content;
			y = (int*)lst->next->content;
			*x ^= *y;
			*y ^= *x;
			*x ^= *y;
		}
		lst = lst->next;
	}
}

void	swap_a(t_list **a, t_list **b)
{
	(void)b;
	swap_list(*a);
	ft_printfnl("sa");
}

void	swap_b(t_list **a, t_list **b)
{
	(void)a;
	swap_list(*b);
	ft_printfnl("sb");
}

void	swap_both(t_list **a, t_list **b)
{
	swap_list(*a);
	swap_list(*b);
	ft_printfnl("ss");
}
