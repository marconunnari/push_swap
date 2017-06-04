/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:24:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/04 19:48:23 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sandwich(t_list *lst, int n, int *smallers, int *biggers)
{
	*smallers = 0;
	*biggers = 0;
	while (lst)
	{
		if (nbr(lst) >= n)
			*biggers = *biggers + 1;
		else
			*smallers = *smallers + 1;
		lst = lst->next;
	}
}

int				find_median(t_list *a, size_t length_a)
{
	size_t		i;
	int		curr;
	int		smallers;
	int		biggers;

	i = 0;
	while (i < length_a)
	{
		curr = nbr(ft_lstat(a, i));
		sandwich(a, curr, &smallers, &biggers);
		if (smallers == length_a / 2 && biggers == length_a / 2 + length_a % 2)
			return (curr);
		i++;
	}
	return (0);
}

int				*list_to_array(t_list *lst, size_t len)
{
	int		i;
	int		*arr;

	i = 0;
	arr = (int*)malloc(sizeof(int) * len);
	while (lst)
	{
		arr[i++] = nbr(lst);
		lst = lst->next;
	}
	return (arr);
}

static int	partition(int *array, int left, int right)
{
	int	q;
	int	j;

	q = left;
	j = left;
	while (j < right)
	{
		if (array[j] < array[right])
			ft_swap_ints(&array[j], &array[q++]);
		j++;
	}
	ft_swap_ints(&array[q], &array[right]);
	return (q);
}

int				quickselect(int *arr, int left, int right, int k)
{
	partition(arr, left, right);
	for(int i = 0; i < right; i++)
		ft_printf("%d ", arr[i]);
	ft_printfnl("end");
	return (k);
}
