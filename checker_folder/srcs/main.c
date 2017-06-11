/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:50:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 17:16:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	int			i;
	int			verbose;

	if (argc == 1)
		exit(0);
	verbose = 0;
	a = parse_args(argc, argv, 1, &verbose);
	b = NULL;
	if (verbose)
		print_stacks(a, b);
	i = perf_cmd(&a, &b, verbose);
	if (verbose)
		ft_printfnl("Performed %d operation%c", i, i == 1 ? '\0' : 's');
	if (check_stacks(a, b))
		ft_printfnl("OK");
	else
		ft_printfnl("KO");
	free_stacks(&a, &b);
}
