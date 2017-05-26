/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 20:01:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 20:03:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_nbr(t_list *elem)
{
	int		*nbr;

	if (elem)
	{
		nbr = (int*)elem->content;
		ft_printf("%-7d", *nbr);
	}
	else
		ft_printf("%-7c", ' ');
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
	ft_printfnl("-----------------");
	boh(a, b);
	ft_printfnl("-------   -------\n%3ca%7cb%3c", ' ', ' ', ' ');
	ft_putchar('\n');
}
