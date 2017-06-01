/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:52:08 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 19:45:15 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

t_list			*parse_args(int argc, char **argv, int start);
void			print_stacks(t_list *a, t_list *b);
int				check_stacks(t_list *a, t_list *b);

#endif
