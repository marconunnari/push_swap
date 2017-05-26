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

t_cmdop		g_cmdops[12] =
{
	{"sa", &swap_a},
	{"sb", &swap_b},
	{"ss", &swap_both},
	{"pa", &push_a},
	{"pb", &push_b},
	{"ra", &rotate_a},
	{"rb", &rotate_b},
	{"rr", &rotate_both},
	{"rra", &reverse_rotate_a},
	{"rrb", &reverse_rotate_b},
	{"rrr", &reverse_rotate_both},
	{NULL, NULL}
};

t_stackop		get_op(char *cmd)
{
	int		i;

	i = 0;
	while (g_cmdops[i].cmd)
	{
		if (ft_strequ(g_cmdops[i].cmd, cmd))
			return (g_cmdops[i].op);
		i++;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	char		*cmd;
	t_stackop	op;

	a = parse_args(argc, argv);
	b = NULL;
	print_stacks(a, b);
	cmd = NULL;
	while (get_next_line(0, &cmd) > 0)
	{
		op = get_op(cmd);
		op(&a, &b);
		print_stacks(a, b);
	}
}
