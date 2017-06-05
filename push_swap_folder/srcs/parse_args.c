/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:28:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 18:56:04 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			is_int(char *arg, t_list *a)
{
	int			i;
	intmax_t	nbr;

	if (!ft_isdigit(arg[0]) && !ft_strcont("+-", arg[0]))
		ps_error(&a, NULL);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ps_error(&a, NULL);
		i++;
	}
	nbr = ft_atoimax(arg);
	if (nbr < INT_MIN || nbr > INT_MAX)
		ps_error(&a, NULL);
}

void			check_duplicate(t_list *a, int nbr)
{
	while (a)
	{
		if (*((int*)a->content) == nbr)
			ps_error(&a, NULL);
		a = a->next;
	}
}

t_list			*parse_arg(char *arg)
{
	char	**argv;
	int		argc;
	t_list	*res;

	argv = ft_strsplit(arg, ' ');
	argc = 0;
	while (argv[argc])
		argc++;
	res = (parse_args(argc, argv, 0));
	while (argc > 0)
		free(argv[--argc]);
	free(argv);
	return (res);
}

t_list			*parse_args(int argc, char **argv, int start)
{
	int		i;
	int		nbr;
	t_list	*elem;
	t_list	*a;

	a = NULL;
	if (argc == 2 && ft_strcont(argv[1], ' '))
		return (parse_arg(argv[1]));
	i = start;
	while (i < argc)
	{
		is_int(argv[i], a);
		nbr = ft_atoi(argv[i]);
		check_duplicate(a, nbr);
		if (!(elem = ft_lstnew(&nbr, sizeof(int))))
			return (NULL);
		if (a == NULL)
			a = elem;
		else
			ft_lstadd(&a, elem);
		i++;
	}
	return (a);
}
