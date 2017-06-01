/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:05:02 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 17:05:33 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				check_stacks(t_list *a, t_list *b)
{
	if (b != NULL)
		return (0);
	while (a && a->next)
	{
		if (*((int*)a->content) < *((int*)a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}
