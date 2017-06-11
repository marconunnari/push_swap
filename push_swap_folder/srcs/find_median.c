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

int				get_smallers(t_list *lst, size_t len, int n)
{
	int	smallers;

	smallers = 0;
	while (lst && len > 0)
	{
		if (nbr(lst) < n)
			smallers++;
		lst = lst->next;
		len--;
	}
	return (smallers);
}

int				find_median(t_list *lst, size_t len)
{
	size_t	i;
	size_t	lstlen;
	int		curr;
	int		smallers;
	int		target;

	lstlen = ft_lstlen(lst);
	i = 0;
	if (lstlen > len)
	{
		lst = ft_lstat(lst, lstlen - len);
	}
	target = len / 2;
	while (i < len)
	{
		curr = nbr(ft_lstat(lst, i));
		smallers = get_smallers(lst, len, curr);
		if (smallers == target)
			return (curr);
		i++;
	}
	return (0);
}
