/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:50:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 19:47:50 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_cmdop			g_cmdops[12] =
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

int				perf_cmd(t_list **a, t_list **b)
{
	char		*cmd;
	t_stackop	op;
	int			i;

	cmd = NULL;
	i = 0;
	while (get_next_line(0, &cmd) > 0)
	{
		ft_printfnl(cmd);
		op = get_op(cmd);
		if (!op)
		{
			//todo: print error and exit
			ft_printf("ERROR: Operation unknown\n\n");
			continue;
		}
		op(a, b);
		print_stacks(*a, *b);
		i++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	int			i;

	a = parse_args(argc, argv, 1);
	b = NULL;
	print_stacks(a, b);
	i = perf_cmd(&a, &b);
	ft_printfnl("Performed %d operation%c", i, i == 1 ? '\0' : 's');
	if (check_stacks(a, b))
		ft_printfnl("OK");
	else
		ft_printfnl("KO");
}
