/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 20:01:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 18:54:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nbr(t_list *elem)
{
	int		*nbr;

	if (elem)
	{
		nbr = (int*)elem->content;
		ft_printf("%-10d", *nbr);
	}
	else
		ft_printf("%-10c", ' ');
}

void	boh(t_list *a, t_list *b)
{
	if (a && b)
		boh(a->next, b->next);
	else if (b)
		boh(a, b->next);
	else if (a)
		boh(a->next, b);
	else
		return ;
	print_nbr(a);
	ft_putstr(" | ");
	print_nbr(b);
	ft_putchar('\n');
}

void	print_stacks(t_list *a, t_list *b)
{
	ft_printfnl("-----------------------");
	boh(a, b);
	ft_printfnl("----------   ----------\n%6ca%7cb%6c", ' ', ' ', ' ');
	ft_putchar('\n');
}
