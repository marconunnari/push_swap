/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:50:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 17:23:47 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;

	a = parse_args(argc, argv, 1);
	b = NULL;
	sort_stacks(&a, &b);
	free_stacks(&a, &b);
}
