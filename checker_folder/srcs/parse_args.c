/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:28:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/02 16:30:04 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			is_int(char *arg)
{
	int			i;
	intmax_t	nbr;

	if (!ft_isdigit(arg[0]) && !ft_strcont("+-", arg[0]))
		ft_error("Error: arg not numeric", 1);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_error("Error: arg not numeric", 1);
		i++;
	}
	nbr = ft_atoimax(arg);
	if (nbr < INT_MIN || nbr > INT_MAX)
		ft_error("Error: arg too big or to little", 1);
}

void			check_duplicate(t_list *a, int nbr)
{
	while (a)
	{
		if (*((int*)a->content) == nbr)
			ft_error("Error: duplicate", 1);
		a = a->next;
	}
}

t_list			*parse_arg(char *arg, int *verbose)
{
	char	**argv;
	int		argc;

	argv = ft_strsplit(arg, ' ');
	argc = 0;
	while (argv[argc])
		argc++;
	return (parse_args(argc, argv, 0, verbose));
}

t_list			*parse_args(int argc, char **argv, int start, int *verbose)
{
	int		i;
	int		nbr;
	t_list	*elem;
	t_list	*a;

	a = NULL;
	if (argc > 1 && ft_strequ(argv[1], "-v"))
	{
		*verbose = 1;
		start++;
	}
	if (argc > 1 && !(*verbose) && ft_strcont(argv[1], ' '))
		return parse_arg(argv[1], verbose);
	if (argc > 2 && (*verbose) && ft_strcont(argv[2], ' '))
		return parse_arg(argv[2], verbose);
	i = start;
	while (i < argc)
	{
		is_int(argv[i]);
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
