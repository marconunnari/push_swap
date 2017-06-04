/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:52:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/04 19:24:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

t_list			*parse_args(int argc, char **argv, int start);
void			print_stacks(t_list *a, t_list *b);
int				check_stacks(t_list *a, t_list *b);
int				stack_sorted(t_list *lst);
void			sort_stacks(t_list **a, t_list **b);
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
int			nbr(t_list *listptr);
void			three_sort(t_list **a);
void			simple_sort(t_list **a, t_list **b, size_t length_a);
int				find_median(t_list *a, size_t length_a);
void			min_to_top(t_list **a, size_t length_a);
void			quick_sort(t_list **a, t_list **b, size_t length_a);
#endif
