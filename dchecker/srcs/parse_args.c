/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:28:45 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 19:29:13 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		nbr = ft_atoi(argv[i]);
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
