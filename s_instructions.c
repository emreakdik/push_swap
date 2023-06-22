/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:58:06 by yakdik            #+#    #+#             */
/*   Updated: 2023/06/21 17:28:19 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "instructions.h"
#include <unistd.h>

static void	s(t_stack *stack)
{
	int	value;
	int	index;

	if (!stack)
		return ;
	value = stack->next->value;
	index = stack->next->index;
	stack->next->value = stack->value;
	stack->next->index = stack->index;
	stack->value = value;
	stack->index = index;
}

void	sa(t_box *box, int flag)
{
	s(box->stack_a);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_box *box, int flag)
{
	s(box->stack_b);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_box *box, int flag)
{
	s(box->stack_a);
	s(box->stack_b);
	if (flag)
		write(1, "ss\n", 3);
}

void	sa_ra(t_box *box, int reverse)
{
	sa(box, 1);
	if (reverse)
		rra(box, 1);
	else
		ra(box, 1);
}
