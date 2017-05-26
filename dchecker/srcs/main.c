/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:50:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 20:01:58 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = parse_args(argc, argv);
	b = NULL;
	print_stacks(a, b);
	swap(&a);
	print_stacks(a, b);
}
