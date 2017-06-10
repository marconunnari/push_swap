/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:25:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 18:56:34 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		partition_b(t_list **a, t_list **b, size_t len)
{
	size_t		i;
	int			median;
	int			n;

	median = find_median(*b, len);
	i = 0;
	while (i++ < len)
	{
		n = nbr(*b);
		reverse_rotate_b(a, b);
		if (n > median)
			push_a(a, b);
	}
}

static void		partition_a(t_list **a, t_list **b, size_t len)
{
	size_t		i;
	int			median;
	int			n;

	median = find_median(*a, len);
	i = 0;
	while (i++ < len)
	{
		n = nbr(*a);
		reverse_rotate_a(a, b);
		if (n <= median)
			push_b(a, b);
	}
}

void			quick_sort_b(t_list **a, t_list **b,
		size_t len, size_t prev_len)
{
	size_t		len_biggers;

	ft_printfnl("quick sort B len %d", len);
	partition_b(a, b, len);
	len_biggers = prev_len / 2;
	ft_printfnl("sort biggers");
	quick_sort_a(a, b, len_biggers, len);
	ft_printfnl("end quick sort B");
}

void			quick_sort_a(t_list **a, t_list **b,
		size_t len, size_t prev_len)
{
	size_t		len_smallers;

	ft_printfnl("quick sort A, len %d", len);
	partition_a(a, b, len);
	len_smallers = ((prev_len - 1) / 2) + 1;
	ft_printfnl("sort smallers");
	quick_sort_b(a, b, len_smallers, len);
	ft_printfnl("end quick sort A");
}
