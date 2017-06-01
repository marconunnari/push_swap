/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:28:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 17:00:21 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			is_int(char *arg)
{
	int		i;

	if (!ft_isdigit(arg[0]) && !ft_strcont("+-", arg[0]))
		ft_error("Error: arg not numeric", 1);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_error("Error: arg not numeric", 1);
		i++;
	}
}

void			check_size(char *arg)
{
	intmax_t	i;

	i = ft_atoimax(arg);
	if (i < INT_MIN || i > INT_MAX)
		ft_error("Error: arg too big or to little", 1);
}

void			check_arg(char *arg)
{
	is_int(arg);
	check_size(arg);
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

t_list			*parse_args(int argc, char **argv)
{
	int		i;
	int		nbr;
	t_list	*elem;
	t_list	*a;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		check_arg(argv[i]);
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
