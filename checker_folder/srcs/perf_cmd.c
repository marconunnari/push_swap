/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perf_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:39:54 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 07:04:40 by mnunnari         ###   ########.fr       */
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

int				perf_cmd(t_list **a, t_list **b, int verbose)
{
	char		*cmd;
	t_stackop	op;
	int			i;

	cmd = NULL;
	i = 0;
	while (get_next_line(0, &cmd) > 0)
	{
		if (verbose)
			ft_printfnl(cmd);
		op = get_op(cmd);
		if (!op)
		{
			free(cmd);
			ps_error(a, b);
		}
		op(a, b);
		if (verbose)
			print_stacks(*a, *b);
		free(cmd);
		i++;
	}
	free(cmd);
	return (i);
}
