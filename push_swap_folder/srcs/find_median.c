/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:24:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 18:55:38 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_smallers(t_list *lst, size_t length_a, int n)
{
	int	smallers;

	smallers = 0;
	while (lst && length_a > 0)
	{
		if (nbr(lst) < n)
			smallers++;
		lst = lst->next;
		length_a--;
	}
	return (smallers);
}

int				find_median(t_list *a, size_t length_a)
{
	size_t	i;
	int		curr;
	int		smallers;
	int		target;

	target = (length_a - 1) / 2;
	i = 0;
	while (i < length_a)
	{
		curr = nbr(ft_lstat(a, i));
		smallers = get_smallers(a, length_a, curr);
		if (smallers == target)
			return (curr);
		i++;
	}
	return (0);
}
