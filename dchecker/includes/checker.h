/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:49:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 16:50:01 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef void	(*t_stackop)(t_list**, t_list**);

typedef struct	s_cmdop
{
	char		*cmd;
	t_stackop	op;
}		t_cmdop;

t_list			*parse_args(int argc, char **argv);
void			print_stacks(t_list *a, t_list *b);

void			swap_a(t_list **a, t_list **b);
void			swap_b(t_list **a, t_list **b);
void			swap_both(t_list **a, t_list **b);

void			push_a(t_list **a, t_list **b);
void			push_b(t_list **a, t_list **b);

void			rotate_a(t_list **a, t_list **b);
void			rotate_b(t_list **a, t_list **b);
void			rotate_both(t_list **a, t_list **b);

void			reverse_rotate_a(t_list **a, t_list **b);
void			reverse_rotate_b(t_list **a, t_list **b);
void			reverse_rotate_both(t_list **a, t_list **b);

#endif
