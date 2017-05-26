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

t_list			*parse_args(int argc, char **argv);
void			swap(t_list **lst);
void			print_stacks(t_list *a, t_list *b);
#endif
