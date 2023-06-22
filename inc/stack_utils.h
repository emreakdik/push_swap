/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:05:59 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/22 13:28:56 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

// Stack Utils
int		stack_size(t_stack *stack);
int		are_values(t_stack *stack, int key_nbr);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);

void	stack_add_back(t_stack **stack, t_stack *new);

#endif