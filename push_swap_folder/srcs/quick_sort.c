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

static t_list		*ft_lstpretail(t_list *lst)
{
	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

static void		partition_b(t_list **a, t_list **b, size_t len)
{
	size_t		i;
	int			median;

	median = find_median(*b, len);
	i = 0;
	while (i++ < len)
	{
		if (nbr(ft_lsttail(*b)) >= median)
			push_a(a, b);
		else
			rotate_b(a, b);
	}
}

void			quick_sort_b(t_list **a, t_list **b, size_t len)
{
	size_t		len_smallers;
	size_t		len_biggers;
	size_t		i;

	if (len == 1)
		return (push_a(a, b));
	else if (len == 2)
	{
		if (nbr(ft_lsttail(*b)) < nbr(ft_lstpretail(*b)))
			swap_b(a, b);
		while (len--)
			push_a(a, b);
		return ;
	}
	partition_b(a, b, len);
	len_smallers = len / 2;
	len_biggers = len - len_smallers;
	i = 0;
	while (i++ < len_smallers)
		reverse_rotate_b(a, b);
	quick_sort_a(a, b, len_biggers, 0);
	quick_sort_b(a, b, len_smallers);
}

static void		partition_a(t_list **a, t_list **b, size_t len)
{
	size_t		i;
	int			median;

	median = find_median(*a, len);
	i = 0;
	while (i++ < len)
	{
		if (nbr(ft_lsttail(*a)) < median)
			push_b(a, b);
		else
			rotate_a(a, b);
	}
}

void			quick_sort_a(t_list **a, t_list **b, size_t len, int is_first)
{
	size_t		len_smallers;
	size_t		len_biggers;
	size_t		i;

	if (len < 2)
		return ;
	if (len == 2)
	{
		if (nbr(ft_lsttail(*a)) > nbr(ft_lstpretail(*a)))
			return (swap_a(a, b));
		else
			return ;
	}
	partition_a(a, b, len);
	len_smallers = len / 2;
	len_biggers = len - len_smallers;
	i = 0;
	if (!is_first)
		while (i++ < len_biggers)
			reverse_rotate_a(a, b);
	quick_sort_a(a, b, len_biggers, is_first);
	quick_sort_b(a, b, len_smallers);
}
