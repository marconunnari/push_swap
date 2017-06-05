/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:54:50 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 17:42:34 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_ptr(void *ptr, size_t size)
{
	(void)size;
	free(ptr);
}

void		free_stacks(t_list **a, t_list **b)
{
	ft_lstdel(a, free_ptr);
	ft_lstdel(b, free_ptr);
}

void		ps_error(t_list **a, t_list **b)
{
	free_stacks(a, b);
	ft_error("Error", 1);
}
