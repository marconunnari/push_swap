/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:30:24 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 19:55:53 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **lst)
{
	t_list	*elem;
	int		*x;
	int		*y;

	ft_printfnl("swap:");
	elem = *lst;
	while (elem)
	{
		if (elem->next && !elem->next->next)
		{
			x = (int*)elem->content;
			y = (int*)elem->next->content;
			*x ^= *y;
			*y ^= *x;
			*x ^= *y;
		}
		elem = elem->next;
	}
}
